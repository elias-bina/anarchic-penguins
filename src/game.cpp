
#include "game.h"

Game::Game(sf::RenderWindow &window) : _window{window} {}

void Game::run() {
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (_window.isOpen()) {
    sf::Event event;
    while (_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        _window.close();
    }

    _window.clear();
    _window.draw(shape);
    _window.display();
  }
}
