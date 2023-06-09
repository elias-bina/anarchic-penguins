#ifndef _AN_PEN_ENVIRONNEMENT_GAMEWORLD
#define _AN_PEN_ENVIRONNEMENT_GAMEWORLD

#include <memory>

#include "entities/player.h"

class GameWorld {
private:
public:
  GameWorld(std::shared_ptr<Player> player);
  GameWorld();
  ~GameWorld();

  void Display(sf::RenderWindow &window);
  void Update(std::chrono::nanoseconds duration);

  std::shared_ptr<Player> _player;
};

#endif //_AN_PEN_ENVIRONNEMENT_GAMEWORLD