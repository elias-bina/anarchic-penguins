#ifndef _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_
#define _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_

#include "utils/position.h"

class WorldEntity {
private:
public:
  virtual void Display() = 0;

  Position _position;
};

#endif //_AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_