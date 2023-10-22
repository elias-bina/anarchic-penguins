#ifndef _AN_PEN_ENVIRONNEMENT_GAMEWORLD
#define _AN_PEN_ENVIRONNEMENT_GAMEWORLD

#include <memory>

#include "entities/player.h"

class GameWorld : public sf::Drawable {
private:
public:
  GameWorld();
  ~GameWorld();

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void Update(std::chrono::nanoseconds duration);

  std::vector<std::shared_ptr<Player>> _player_list;
};

#endif //_AN_PEN_ENVIRONNEMENT_GAMEWORLD
