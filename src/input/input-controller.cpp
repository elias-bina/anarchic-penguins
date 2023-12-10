
#include <iostream>
#include <unordered_map>

#include "input/input-controller.h"


static std::unordered_map<sf::Keyboard::Key, DigitalActionState> _keyboard_to_action = {
    {sf::Keyboard::Tab, DigitalActionState::MAP_ACTION},
    {sf::Keyboard::Escape, DigitalActionState::PAUSE_ACTION},

    {sf::Keyboard::A, DigitalActionState::LEFT_BUTTON_ACTION},
    {sf::Keyboard::E, DigitalActionState::RIGHT_BUTTON_ACTION},

    {sf::Keyboard::Space, DigitalActionState::A_BUTTON_ACTION},

    {sf::Keyboard::Left, DigitalActionState::PRIMARY_LEFT_BUTTON},
    {sf::Keyboard::Right, DigitalActionState::PRIMARY_RIGHT_BUTTON},
    {sf::Keyboard::Up, DigitalActionState::PRIMARY_UP_BUTTON},
    {sf::Keyboard::Down, DigitalActionState::PRIMARY_DOWN_BUTTON},

    {sf::Keyboard::LShift, DigitalActionState::PRIMARY_JOY_CLICK},
    {sf::Keyboard::LControl, DigitalActionState::SECONDARY_JOY_CLICK},
};

static std::unordered_map<sf::Mouse::Button, DigitalActionState> _mouse_to_action = {
    {sf::Mouse::Left, DigitalActionState::X_BUTTON_ACTION},
    {sf::Mouse::Right, DigitalActionState::B_BUTTON_ACTION},

    {sf::Mouse::Middle, DigitalActionState::Y_BUTTON_ACTION},
};


// TODO: Check if this is the right mapping
static std::unordered_map<uint32_t, DigitalActionState> _joystick_to_action = {
    {0, DigitalActionState::X_BUTTON_ACTION},     {1, DigitalActionState::A_BUTTON_ACTION},
    {2, DigitalActionState::B_BUTTON_ACTION},     {3, DigitalActionState::Y_BUTTON_ACTION},
    {4, DigitalActionState::LEFT_BUTTON_ACTION},  {5, DigitalActionState::RIGHT_BUTTON_ACTION},
    {6, DigitalActionState::PRIMARY_LEFT_BUTTON}, {7, DigitalActionState::PRIMARY_RIGHT_BUTTON},
    {8, DigitalActionState::PRIMARY_UP_BUTTON},   {9, DigitalActionState::PRIMARY_DOWN_BUTTON},
    {10, DigitalActionState::PRIMARY_JOY_CLICK},  {11, DigitalActionState::SECONDARY_JOY_CLICK},
    {12, DigitalActionState::MAP_ACTION},         {13, DigitalActionState::PAUSE_ACTION},
};

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

sf::Vector2f InputController::get_vector_move() { return _analog_actions.get_primary_state(); }
sf::Vector2f InputController::get_vector_camera() { return _analog_actions.get_secondary_state(); }

void InputController::set_axis_value(AnalogActionState axis, float value) {
  _analog_actions.set_axis_value(axis, value);
}
void InputController::set_button_value(DigitalActionState button, bool value) {
  _digital_actions.set_button_value(button, value);
}

void InputController::set_key_value(sf::Keyboard::Key key, bool value) {
  set_button_value(_keyboard_to_action.at(key), value);
}
void InputController::set_mouse_button_value(sf::Mouse::Button button, bool value) {
  set_button_value(_mouse_to_action.at(button), value);
}

void InputController::set_joystick_button_value(uint32_t button, bool value) {
  set_button_value(_joystick_to_action.at(button), value);
}


float InputController::get_trigger(AnalogActionState axis) { return _analog_actions.get_trigger(axis); }

bool InputController::get_button_value(DigitalActionState button) { return _digital_actions.get_button_value(button); }
