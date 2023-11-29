
#include <chrono>
#include <iostream>
#include <thread>
#include <unistd.h>

#include "game.h"

void Game::updateThreadFunc() {
  _curr_time = std::chrono::steady_clock::now();

  while (_window.isOpen()) {
    _prev_time = _curr_time;
    _curr_time = std::chrono::steady_clock::now();
    _gameworld.Update(std::chrono::duration_cast<std::chrono::nanoseconds>(_curr_time - _prev_time));
  }
}

Game::Game(sf::RenderWindow &window)
    : _window{window}, _main_view{sf::Vector2f(0.0, 0.0), sf::Vector2f(window.getSize())}, _gameworld{GameWorld()},
      _input_manager{} {}

void Game::run() {
  _window.setView(_main_view);

  std::thread updateThread(&Game::updateThreadFunc, this);


  _gameworld.add_new_player(Player());
  _gameworld.add_new_player(Player());


  while (_window.isOpen()) {
    // TODO: si un joystick unbind appuie sur un bouton, il prend le contrôle d'un player
    sf::Event event;
    while (_window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        _window.close();
        break;

      case sf::Event::JoystickButtonPressed:
        if (_gameworld.has_uncontrolled_player()) {
          InputController *controller = _input_manager.controllerFromIndex(event.joystickButton.joystickId);
          if (!controller->has_player())
            _gameworld.bind_player(controller);
        }
        break;

      case sf::Event::JoystickConnected:
        _input_manager.connectJoystick(event.joystickConnect.joystickId);
        break;

      case sf::Event::JoystickDisconnected:
        _input_manager.disconnectJoystick(event.joystickConnect.joystickId);
        break;

      case sf::Event::KeyPressed: {
        InputController *controller = _input_manager.controllerWithKeyboard();
        if (_gameworld.has_uncontrolled_player()) {
          if (!controller->has_player())
            _gameworld.bind_player(controller);
        }
        break;
      }

      default:
        break;
      }
    }

    // TODO: Linked list of events to set the state byt getting the right controller (sort the list ?)

    // // TODO: Check if there is a player with unbinded controller
    // Player * player = _gameworld.get_free_player(NEXT_PLAYER, 0);
    // if(player)
    //   player->set_input_controller();

    _window.clear();
    _window.draw(_gameworld);
    _window.display();
  }
  updateThread.join();
}
