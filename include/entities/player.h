#ifndef _AN_PEN_ENTITIES_PLAYER
#define _AN_PEN_ENTITIES_PLAYER

#include "entities/entity.h"
class Player;
#include "input/input-controller.h"

class Player : public Entity {
private:
  std::shared_ptr<InputController> _controller;

public:
  Player();
  ~Player();

  void Update(std::chrono::nanoseconds duration);

  void move_x_pixels(float pos);
  void move_y_pixels(float pos);
  void move_at_random(std::chrono::nanoseconds duration);

  void set_input_controller(std::shared_ptr<InputController> controller);
  bool has_controller();

  bool _has_set_seed = false;
};

#endif //_AN_PEN_ENTITIES_PLAYER
