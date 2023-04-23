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

  std::shared_ptr<Player> _player;
};

#endif //_AN_PEN_ENVIRONNEMENT_GAMEWORLD