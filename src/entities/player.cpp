
#include "entities/player.h"
#include "constants.h"

#include <iostream>

constexpr float player_size = 100;

Player::Player() : Entity() {
  _sprite_shape = std::shared_ptr<sf::Shape>(new sf::CircleShape(player_size));
  _sprite_shape->setFillColor(sf::Color::Green);
}

Player::~Player() {}

void Player::Display(sf::RenderWindow &window) {
  if (_sprite_shape != nullptr) {
    _sprite_shape->setPosition(sf::Vector2f(
        window_size_x / 2 - player_size + graphic_step * _position._x,
        window_size_y / 2 - player_size + graphic_step * _position._y));
    window.draw(*_sprite_shape);
  }
}

void Player::Update(std::chrono::nanoseconds duration) {
  move_at_random();
  constexpr std::chrono::nanoseconds ms = std::chrono::milliseconds(1);
  std::cout << "Time elapsed : " << duration / ms << "ms" << std::endl;
  return;
}

void Player::move_x(int32_t pos) { _position._x += pos; }
void Player::move_y(int32_t pos) { _position._y += pos; }

void Player::move_at_random() {
  if (!_has_set_seed) {
    std::srand(std::time(nullptr));
    _has_set_seed = true;
  }
  for (uint32_t i = 0; i < 10; i++) {
    int choice = std::rand() % 4;
    switch (choice) {
    case 0:
      move_x(1);
      break;
    case 1:
      move_x(-1);
      break;
    case 2:
      move_y(1);
      break;
    case 3:
      move_y(-1);
      break;

    default:
      break;
    }
  }
}