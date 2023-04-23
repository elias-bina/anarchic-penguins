#include "utils/position.h"

class WorldEntity {
private:
public:
  virtual void Display() = 0;

  Position _position;
};