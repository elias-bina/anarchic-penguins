#include <SFML/Graphics.hpp>

#include <iostream>

#include "input/input-manager.h"

InputManager::InputManager() : _is_keyboard_mapped{false} {
  for (size_t num_joystick = 0; num_joystick < sf::Joystick::Count; num_joystick++) {
    if (sf::Joystick::isConnected(num_joystick)) {
      _controller_list.push_back(InputController(num_joystick, !_is_keyboard_mapped));
      _is_keyboard_mapped = true;
    }
  }

  if (!_is_keyboard_mapped)
    _controller_list.push_back(InputController(true));
  _is_keyboard_mapped = true;
}


void InputManager::connectJoystick(uint32_t joystick_id) {
  // Connect only if it exists
  if (std::any_of(_controller_list.begin(), _controller_list.end(),
                  [joystick_id](InputController c) { return c.get_joystick_index() == joystick_id; })) {
    return;
  }

  if (_controller_list.size() == 1 && !_controller_list[0].has_joystick()) {
    _controller_list[0].set_joystick(joystick_id);
  } else {
    _controller_list.push_back(InputController(joystick_id, false));
  }
  return;
}


void InputManager::disconnectJoystick(uint32_t joystick_id) {
  // Find the right controller to erase
  std::vector<InputController>::iterator controller_iterator =
      std::find_if(_controller_list.begin(), _controller_list.end(),
                   [joystick_id](InputController c) { return c.get_joystick_index() == joystick_id; });

  if (controller_iterator == _controller_list.end())
    return;


  InputController controller = *controller_iterator;
  _controller_list.erase(controller_iterator);

  // Give the keyboard to another player
  // TODO : Prevent keyboard property theft for some seconds ?
  if (controller.has_keyboard()) {
    if (_controller_list.size() > 0) {
      _controller_list[0].give_keyboard();
    } else {
      _controller_list.push_back(InputController(true));
    }
  }
}

InputController *InputManager::controllerFromIndex(uint32_t controller_index) {
  std::vector<InputController>::iterator controller_iterator =
      std::find_if(_controller_list.begin(), _controller_list.end(),
                   [controller_index](InputController c) { return c.get_joystick_index() == controller_index; });

  if (controller_iterator == _controller_list.end())
    return nullptr;

  return &(*controller_iterator);
}
