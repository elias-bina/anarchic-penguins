
#include <iostream>

#include "input/input-controller.h"


InputController::InputController(int32_t joystick_index, bool map_keyboard_to_this)
    : _joystick_index{joystick_index}, _is_keyboard_holder{map_keyboard_to_this}, _has_player{false} {}

InputController::InputController(bool map_keyboard_to_this) : InputController(UNDEFINED_INDEX, map_keyboard_to_this) {}

InputController::InputController() : InputController(false) {}

InputController::~InputController() {}

void InputController::set_joystick(int32_t joystick_index) { _joystick_index = joystick_index; }
int32_t InputController::get_joystick_index() { return _joystick_index; }
bool InputController::has_joystick() { return _joystick_index != UNDEFINED_INDEX; }


void InputController::set_player() { _has_player = true; }
void InputController::remove_player() { _has_player = false; }
bool InputController::has_player() { return _has_player; }


void InputController::give_keyboard() { _is_keyboard_holder = true; }
void InputController::remove_keyboard() { _is_keyboard_holder = false; }
bool InputController::has_keyboard() { return _is_keyboard_holder; }
