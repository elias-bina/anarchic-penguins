#ifndef _AN_PEN_ENVIRONNEMENT_GAME_H_
#define _AN_PEN_ENVIRONNEMENT_GAME_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include "environnement/gameworld.h"
#include "input/input-manager.h"

class Game {
private:
  void updateThreadFunc();

  sf::RenderWindow &_window;
  // TODO : Create a real view management class (for multiplayer and minimap)
  sf::View _main_view;

  GameWorld _gameworld;

  InputManager _input_manager;

  std::chrono::time_point<std::chrono::steady_clock> _curr_time;
  std::chrono::time_point<std::chrono::steady_clock> _prev_time;

public:
  explicit Game(sf::RenderWindow &window);

  void run();
};

#endif //_AN_PEN_ENVIRONNEMENT_GAME_H_
