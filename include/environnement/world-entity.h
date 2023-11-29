#ifndef _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_
#define _AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_

#include <chrono>
#include <memory>

#include <SFML/Graphics.hpp>

#include "utils/position.h"

class WorldEntity : public sf::Transformable, public sf::Drawable {
private:
protected:
  std::shared_ptr<sf::Shape> _sprite_shape;

public:
  int32_t _z_position;
  int32_t _z_plane;

  WorldEntity();

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  virtual void Update(std::chrono::nanoseconds duration) = 0;
};
#endif //_AN_PEN_ENVIRONNEMENT_WORLDENTITY_H_
