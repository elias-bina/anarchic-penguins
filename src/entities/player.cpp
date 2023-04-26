
#include "entities/player.h"
#include "constants.h"

#include <iostream>

Player::Player() : Entity() {}

Player::~Player() {}

void Player::Update(std::chrono::nanoseconds duration) {
  move_at_random();
  constexpr std::chrono::nanoseconds ms = std::chrono::milliseconds(1);
  std::cout << "Time elapsed : " << duration / ms << "ms" << std::endl;
  return;
}

void Player::move_x(float pos) {
  this->setPosition(this->getPosition() + sf::Vector2f(pos, 0.0f));
}
void Player::move_y(float pos) {
  this->setPosition(this->getPosition() + sf::Vector2f(0.0f, pos));
}

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