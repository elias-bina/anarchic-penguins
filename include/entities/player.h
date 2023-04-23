#ifndef _AN_PEN_ENTITIES_PLAYER
#define _AN_PEN_ENTITIES_PLAYER

#include <entities/entity.h>

class Player : Entity {
private:
public:
  Player();
  ~Player();

  void Display();

  void move_x(int32_t pos);
  void move_y(int32_t pos);

  Position _position;
};

#endif //_AN_PEN_ENTITIES_PLAYER