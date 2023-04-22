
#include "entities/player.h"

Player::Player() : _pos_x{0}, _pos_y{0} {}

Player::~Player() {}

void Player::move_x(uint32_t pos) { _pos_x += pos; }
void Player::move_y(uint32_t pos) { _pos_y += pos; }