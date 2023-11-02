#include <iostream>

#include "constants.h"
#include "environnement/world-entity.h"

WorldEntity::WorldEntity()
    : _z_position{0}, _z_plane{0}, _sprite_shape{std::shared_ptr<sf::Shape>(new sf::RectangleShape(
                                       sf::Vector2f(default_entity_size_x, default_entity_size_y)))} {
  _sprite_shape->setOrigin(_sprite_shape->getScale() / 2.0f);
  _sprite_shape->setFillColor(sf::Color::Green);
}

void WorldEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (_sprite_shape != nullptr) {
    // TODO : Update position only if entity position change or window move ->
    // And update only if in the range of view
    //  & update size only if size change :) -> Getter / Setter
    _sprite_shape->setPosition(this->getPosition());
    target.draw(*_sprite_shape, states);
  }
};
