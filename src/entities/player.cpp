
#include "entities/player.h"

Player::Player() : _position{0, 0, 0} {}

Player::~Player() {}

void Player::Display() {}

void Player::move_x(int32_t pos) { _position._x += pos; }
void Player::move_y(int32_t pos) { _position._y += pos; }