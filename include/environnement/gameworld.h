#include <memory>

#include "entities/player.h"

class GameWorld {
private:
public:
  GameWorld(std::shared_ptr<Player> player);
  ~GameWorld();

  std::shared_ptr<Player> _player;
};
