#include <cstdint>

class Player {
private:
public:
  Player();
  ~Player();

  uint32_t _pos_x;
  uint32_t _pos_y;

  void move_x(uint32_t pos);
  void move_y(uint32_t pos);
};
