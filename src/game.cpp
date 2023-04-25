
#include <chrono>
#include <thread>

#include "game.h"

Game::Game(sf::RenderWindow &window) : _window{window} {}

void Game::run() {
  _pre_update = std::chrono::steady_clock::now();
  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        _window.close();
    }

    _window.clear();

    _post_update = _pre_update;
    _pre_update = std::chrono::steady_clock::now();
    _gameworld.Update(std::chrono::duration_cast<std::chrono::nanoseconds>(
        _pre_update - _post_update));

    _gameworld.Display(_window);

    _window.display();
  }
}
