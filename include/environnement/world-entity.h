#ifndef _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_
#define _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_

#include <chrono>
#include <memory>

#include <SFML/Graphics.hpp>

#include "utils/position.h"

class WorldEntity {
private:
protected:
  std::shared_ptr<sf::Shape> _sprite_shape;

public:
  WorldEntity();

  virtual void Display(sf::RenderWindow &window) = 0;
  virtual void Update(std::chrono::nanoseconds duration) = 0;

  Position _position;
};
#endif //_AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_