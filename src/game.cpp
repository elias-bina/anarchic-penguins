
#include <chrono>
#include <iostream>
#include <thread>

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

  _gameworld._player_list.push_back(Player());

  std::thread updateThread(&Game::updateThreadFunc, this);

  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        _window.close();
        break;

      case sf::Event::JoystickConnected:
        _input_manager.connectJoystick(event.joystickConnect.joystickId);
        break;

      case sf::Event::JoystickDisconnected:
        _input_manager.disconnectJoystick(event.joystickConnect.joystickId);
        break;

      default:
        break;
      }
    }

    _window.clear();
    _window.draw(_gameworld);
    _window.display();
  }
  updateThread.join();
}
