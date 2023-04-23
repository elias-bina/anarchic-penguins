
#include <entities/entity.h>

class Player : Entity {
private:
public:
  Player();
  ~Player();

  void Display();

  void move_x(uint32_t pos);
  void move_y(uint32_t pos);

  Position _position;
};
