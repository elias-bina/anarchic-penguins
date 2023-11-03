#include "entities/player.h"
#include "constants.h"

#include <iostream>

// Speed constants : Pixel per seconds
constexpr float MAX_PLAYER_SPEED = 200.0f;
constexpr int32_t NB_MILLISECONDS_RANDOM_CONTINUES = 50;

Player::Player()
    : Entity(), _controller{nullptr},
      gen(std::random_device()()), distrib{0, 3}, choice{0}, last_move_choice{std::chrono::steady_clock::now()} {}

Player::~Player() {}

void Player::Update(std::chrono::nanoseconds duration) {
  if (has_controller()) {
  } else {
    move_at_random(duration);
  }
  constexpr std::chrono::nanoseconds microsec = std::chrono::microseconds(1);
  // std::cout << "Time elapsed : " << duration / microsec << "µs" << std::endl;
  return;
}

void Player::move_x_pixels(float pos) { this->setPosition(this->getPosition() + sf::Vector2f(pos, 0.0f)); }
void Player::move_y_pixels(float pos) { this->setPosition(this->getPosition() + sf::Vector2f(0.0f, pos)); }

// TODO: WIP: If there is an AI, it should be in its own class, not polluting player
void Player::move_at_random(std::chrono::nanoseconds duration) {
  float displacement = MAX_PLAYER_SPEED * duration / std::chrono::seconds(1);

  if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - last_move_choice) >
      std::chrono::milliseconds(NB_MILLISECONDS_RANDOM_CONTINUES)) {
    choice = distrib(gen) % 4;
    last_move_choice = std::chrono::steady_clock::now();
  }
  switch (choice) {
  case 0:
    move_x_pixels(displacement);
    break;
  case 1:
    move_x_pixels(-displacement);
    break;
  case 2:
    move_y_pixels(displacement);
    break;
  case 3:
    move_y_pixels(-displacement);
    break;

  default:
    break;
  }
}

void Player::set_input_controller(InputController *controller) { _controller = controller; }
void Player::unset_input_controller() { _controller = nullptr; }

bool Player::has_controller() { return _controller != nullptr; }
