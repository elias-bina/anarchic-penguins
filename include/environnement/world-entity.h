#ifndef _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_
#define _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_

#include <memory>

#include <SFML/Graphics.hpp>

#include "utils/position.h"

class WorldEntity {
private:
protected:
  std::shared_ptr<sf::Shape> _sprite_shape;

public:
  virtual void Display(sf::RenderWindow &window) = 0;

  Position _position;
};

#endif //_AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_