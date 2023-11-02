#ifndef _AN_PEN_ENTITIES_PLAYER
#define _AN_PEN_ENTITIES_PLAYER

#include <random>

#include "entities/entity.h"
class Player;
#include "input/input-controller.h"

class Player : public Entity {
private:
  std::shared_ptr<InputController> _controller;

public:
  Player();
  ~Player();

  void Update(std::chrono::nanoseconds duration) override;

  void move_x_pixels(float pos);
  void move_y_pixels(float pos);
  void move_at_random(std::chrono::nanoseconds duration);

  void set_input_controller(std::shared_ptr<InputController> controller);
  void unset_input_controller();

  bool has_controller();

  std::mt19937 gen;
  std::uniform_int_distribution<> distrib;

  std::chrono::time_point<std::chrono::steady_clock> last_move_choice;
  int choice = 0;
};

#endif //_AN_PEN_ENTITIES_PLAYER
