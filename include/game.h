#ifndef _AN_PEN_ENVIRONNEMENT_GAME_H_
#define _AN_PEN_ENVIRONNEMENT_GAME_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include "environnement/gameworld.h"

class Game {
private:
  sf::RenderWindow &_window;

  GameWorld _gameworld;

  std::chrono::time_point<std::chrono::steady_clock> _pre_update;
  std::chrono::time_point<std::chrono::steady_clock> _post_update;

public:
  Game(sf::RenderWindow &window);

  void run();
};

#endif //_AN_PEN_ENVIRONNEMENT_GAME_H_