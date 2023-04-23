#ifndef _AN_PEN_ENTITIES_PLAYER
#define _AN_PEN_ENTITIES_PLAYER

#include <entities/entity.h>

constexpr int32_t graphic_step = 10;

class Player : Entity {
private:
public:
  Player();
  ~Player();

  void Display(sf::RenderWindow &window);

  void move_x(int32_t pos);
  void move_y(int32_t pos);

  void move_at_random();

  Position _position;

  bool _has_set_seed = false;
};

#endif //_AN_PEN_ENTITIES_PLAYER