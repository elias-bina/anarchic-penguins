#ifndef _AN_PEN_ENVIRONNEMENT_GAMEWORLD
#define _AN_PEN_ENVIRONNEMENT_GAMEWORLD

#include <memory>
#include <mutex>
#include <optional>

#include "entities/player.h"

enum NewPlayerChoice {
  PREVIOUS_PLAYER,
  NEXT_PLAYER,
  RANDOM_PLAYER
};

class GameWorld : public sf::Drawable {
public:
  GameWorld();
  ~GameWorld();

  void add_new_player(Player Player);
  void bind_player(InputController *input_controller);
  void unbind_player(InputController *input_controller);

  bool has_uncontrolled_player();

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void Update(std::chrono::nanoseconds duration);

  std::mutex _player_list_mutex;
  std::mutex _player_disp_list_mutex;

private:
  Player *get_free_player(NewPlayerChoice player_choice, uint32_t player_index);

  bool _all_player_controlled;
  std::vector<Player> _player_list;
};

#endif //_AN_PEN_ENVIRONNEMENT_GAMEWORLD
