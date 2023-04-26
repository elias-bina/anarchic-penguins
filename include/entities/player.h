#ifndef _AN_PEN_ENTITIES_PLAYER
#define _AN_PEN_ENTITIES_PLAYER

#include <entities/entity.h>

class Player : public Entity {
private:
public:
  Player();
  ~Player();

  void Update(std::chrono::nanoseconds duration);

  void move_x_pixels(float pos);
  void move_y_pixels(float pos);

  void move_at_random(std::chrono::nanoseconds duration);

  bool _has_set_seed = false;
};

#endif //_AN_PEN_ENTITIES_PLAYER