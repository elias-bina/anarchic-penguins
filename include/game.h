#ifndef _AN_PEN_ENVIRONNEMENT_GAME_H_
#define _AN_PEN_ENVIRONNEMENT_GAME_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include "environnement/gameworld.h"

class Game {
private:
  sf::RenderWindow &_window;

  GameWorld _gameworld;

public:
  Game(sf::RenderWindow &window);

  void run();
};

#endif //_AN_PEN_ENVIRONNEMENT_GAME_H_