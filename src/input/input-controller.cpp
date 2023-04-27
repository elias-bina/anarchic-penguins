
#include <iostream>

#include "input/input-controller.h"

constexpr int32_t UNDEFINED_CONTROLLER = -1;

InputController::InputController(int32_t joystick_index, bool map_keyboard_to_this)
    : _joystick_index{joystick_index}, _is_keyboard_holder{map_keyboard_to_this} {
  std::cout << "Joystick connected : " << joystick_index << ", Keyboard : " << map_keyboard_to_this << std::endl;
}

InputController::InputController(bool map_keyboard_to_this)
    : InputController(UNDEFINED_CONTROLLER, map_keyboard_to_this) {}


void InputController::add_joystick(int32_t joystick_index) { _joystick_index = joystick_index; }
int32_t InputController::get_joystick_index() { return _joystick_index; }
bool InputController::has_joystick() { return _joystick_index != UNDEFINED_CONTROLLER; }


void InputController::give_keyboard() { _is_keyboard_holder = true; }
bool InputController::has_keyboard() { return _is_keyboard_holder; }

void InputController::set_controlled_player(std::shared_ptr<Player> player) {
  _controlled_player = player;
  player->set_input_controller(std::shared_ptr<InputController>(this));
}
