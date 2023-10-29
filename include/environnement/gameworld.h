#ifndef _AN_PEN_ENVIRONNEMENT_GAMEWORLD
#define _AN_PEN_ENVIRONNEMENT_GAMEWORLD

#include <memory>
#include <optional>

#include "entities/player.h"

enum NewPlayerChoice {
  PREVIOUS_PLAYER,
  NEXT_PLAYER,
  RANDOM_PLAYER
};

class GameWorld : public sf::Drawable {
private:
public:
  GameWorld();
  ~GameWorld();

  std::optional<Player *> get_free_player(NewPlayerChoice player_choice, uint32_t player_index);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void Update(std::chrono::nanoseconds duration);

  std::vector<Player> _player_list;
};

#endif //_AN_PEN_ENVIRONNEMENT_GAMEWORLD
