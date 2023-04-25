#ifndef _AN_PEN_ENVIRONNEMENT_GAME_H_
#define _AN_PEN_ENVIRONNEMENT_GAME_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include "environnement/gameworld.h"

class Game {
private:
  void renderThreadFunc();
  void updateThreadFunc();

  sf::RenderWindow &_window;

  GameWorld _gameworld;

  std::chrono::time_point<std::chrono::steady_clock> _curr_time;
  std::chrono::time_point<std::chrono::steady_clock> _prev_time;

public:
  Game(sf::RenderWindow &window);

  void run();
};

#endif //_AN_PEN_ENVIRONNEMENT_GAME_H_