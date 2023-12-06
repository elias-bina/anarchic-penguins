#include <SFML/Graphics.hpp>

#include <iostream>

#include "input/input-manager.h"


InputManager::InputManager() : InputManager{true} {}

InputManager::InputManager(bool auto_connect) : _is_keyboard_mapped{false} {
  if (auto_connect) {
    for (unsigned int num_joystick = 0; num_joystick < sf::Joystick::Count; num_joystick++) {
      if (sf::Joystick::isConnected(num_joystick)) {
        _controller_list[num_joystick] = InputController(num_joystick, !_is_keyboard_mapped);
        _is_keyboard_mapped = true;
      }
    }
  }

  if (!_is_keyboard_mapped)
    _controller_list[UNDEFINED_INDEX] = InputController(true);
  _is_keyboard_mapped = true;
}


void InputManager::connectJoystick(uint32_t joystick_id) {
  // Connect only if it exists
  if (_controller_list.find(joystick_id) != _controller_list.end())
    return;

  if (_controller_list.find(UNDEFINED_INDEX) != _controller_list.end()) {
    _controller_list[joystick_id] = _controller_list[UNDEFINED_INDEX];
    _controller_list[joystick_id].set_joystick(joystick_id);
    _controller_list.erase(UNDEFINED_INDEX);
  } else {
    _controller_list[joystick_id] = InputController(joystick_id, false);
  }
  return;
}


void InputManager::disconnectJoystick(uint32_t joystick_id) {
  // Find the right controller to erase
  std::unordered_map<int32_t, InputController>::iterator controller_iterator = _controller_list.find(joystick_id);
  if (controller_iterator == _controller_list.end())
    return;


  InputController controller = controller_iterator->second;
  _controller_list.erase(controller_iterator);

  // Give the keyboard to another player
  // TODO : Prevent keyboard property theft for some seconds ?
  if (controller.has_keyboard()) {
    if (_controller_list.size() > 0) {
      _controller_list[_controller_list.begin()->first].give_keyboard();
    } else {
      _controller_list[UNDEFINED_INDEX] = InputController(true);
    }
  }
}

InputController *InputManager::controllerFromIndex(uint32_t controller_index) {
  std::unordered_map<int32_t, InputController>::iterator controller_iterator = _controller_list.find(controller_index);
  if (controller_iterator == _controller_list.end()) {
    return nullptr;
  }

  return &controller_iterator->second;
}

InputController *InputManager::controllerWithKeyboard() {
  if (_controller_list.find(UNDEFINED_INDEX) != _controller_list.end()) {
    return &_controller_list[UNDEFINED_INDEX];
  }
  std::unordered_map<int32_t, InputController>::iterator controller_iterator =
      std::find_if(_controller_list.begin(), _controller_list.end(),
                   [](std::pair<int32_t, InputController> c) { return c.second.has_keyboard(); });
  if (controller_iterator == _controller_list.end()) {
    return nullptr;
  }
  return &controller_iterator->second;
}
