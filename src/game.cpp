
#include <chrono>
#include <iostream>
#include <thread>

#include "game.h"

void Game::updateThreadFunc() {
  _curr_time = std::chrono::steady_clock::now();

  while (_window.isOpen()) {
    _prev_time = _curr_time;
    _curr_time = std::chrono::steady_clock::now();
    _gameworld.Update(std::chrono::duration_cast<std::chrono::nanoseconds>(
        _curr_time - _prev_time));
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

Game::Game(sf::RenderWindow &window)
    : _window{window}, _main_view{sf::Vector2f(0.0, 0.0),
                                  sf::Vector2f(window.getSize())} {}

void Game::run() {
  _window.setView(_main_view);

  std::thread updateThread(&Game::updateThreadFunc, this);

  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        _window.close();
    }

    _window.clear();
    _window.draw(_gameworld);
    _window.display();
  }
  updateThread.join();
}
