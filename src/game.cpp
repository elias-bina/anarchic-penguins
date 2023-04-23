
#include "game.h"

Game::Game(sf::RenderWindow &window) : _window{window} {}

void Game::run() {

  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        _window.close();
    }

    _window.clear();

    _gameworld._player->move_at_random();
    _gameworld.Display(_window);

    _window.display();
  }
}
