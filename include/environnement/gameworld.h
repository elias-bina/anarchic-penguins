#ifndef _AN_PEN_ENVIRONNEMENT_GAMEWORLD
#define _AN_PEN_ENVIRONNEMENT_GAMEWORLD

#include <memory>

#include "entities/player.h"

class GameWorld : public sf::Drawable {
private:
public:
  GameWorld(std::shared_ptr<Player> player);
  GameWorld();
  ~GameWorld();

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void Update(std::chrono::nanoseconds duration);

  std::shared_ptr<Player> _player;
};

#endif //_AN_PEN_ENVIRONNEMENT_GAMEWORLD