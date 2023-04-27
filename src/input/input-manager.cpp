#include <iostream>

#include "input/input-manager.h"

std::shared_ptr<Player> InputManager::get_free_player(NewPlayerChoice player_choice, uint32_t from_player_index) {
  if (player_choice == NewPlayerChoice::RANDOM_PLAYER) {
    // TODO : Real rand
    from_player_index = 0;
  } else if (from_player_index >= _player_list.size()) {
    return nullptr;
  }

  if (player_choice == NewPlayerChoice::NEXT_PLAYER) {
    std::vector<std::shared_ptr<Player>>::iterator free_player_iterator;

    std::vector<std::shared_ptr<Player>>::iterator search_start_it = _player_list.begin();
    std::advance(search_start_it, from_player_index);

    free_player_iterator = std::find_if(search_start_it, _player_list.end(),
                                        [](std::shared_ptr<Player> p) { return !p->has_controller(); });

    if (free_player_iterator == _player_list.end()) {
      free_player_iterator = std::find_if(_player_list.begin(), search_start_it,
                                          [](std::shared_ptr<Player> p) { return !p->has_controller(); });
      if (free_player_iterator == search_start_it) {
        return nullptr;
      }
    }
    return *free_player_iterator;
  } else if (player_choice == NewPlayerChoice::PREVIOUS_PLAYER) {
    std::vector<std::shared_ptr<Player>>::reverse_iterator free_player_iterator;

    std::vector<std::shared_ptr<Player>>::reverse_iterator search_start_it = _player_list.rbegin();
    std::advance(search_start_it, (_player_list.size() - 1) - from_player_index);

    free_player_iterator = std::find_if(search_start_it, _player_list.rend(),
                                        [](std::shared_ptr<Player> p) { return !p->has_controller(); });

    if (free_player_iterator == _player_list.rend()) {
      free_player_iterator = std::find_if(_player_list.rbegin(), search_start_it,
                                          [](std::shared_ptr<Player> p) { return !p->has_controller(); });
      if (free_player_iterator == search_start_it) {
        return nullptr;
      }
    }
    return *free_player_iterator;
  }
  return nullptr;
}


InputController InputManager::create_new_controller(uint32_t controller_index, bool map_keyboard_to_this) {
  InputController controller = InputController(controller_index, map_keyboard_to_this);
  std::shared_ptr<Player> free_player = get_free_player(NewPlayerChoice::NEXT_PLAYER, 0);
  if (free_player != nullptr)
    controller.set_controlled_player(free_player);
  return controller;
}
InputController InputManager::create_new_controller(bool map_keyboard_to_this) {
  InputController controller = InputController(map_keyboard_to_this);
  std::shared_ptr<Player> free_player = get_free_player(NewPlayerChoice::NEXT_PLAYER, 0);
  if (free_player != nullptr)
    controller.set_controlled_player(free_player);
  return controller;
}


InputManager::InputManager(std::vector<std::shared_ptr<Player>> &player_list)
    : _is_keyboard_mapped{false}, _player_list{player_list} {
  for (size_t num_joystick = 0; num_joystick < sf::Joystick::Count; num_joystick++) {
    if (sf::Joystick::isConnected(num_joystick)) {
      _controller_list.push_back(create_new_controller(num_joystick, !_is_keyboard_mapped));
      _is_keyboard_mapped = true;
    }
  }

  if (!_is_keyboard_mapped)
    _controller_list.push_back(create_new_controller(true));
  _is_keyboard_mapped = true;
}


void InputManager::connectJoystick(uint32_t joystick_id) {
  // Connect only if it exists
  if (std::any_of(_controller_list.begin(), _controller_list.end(),
                  [joystick_id](InputController c) { return c.get_joystick_index() == joystick_id; })) {
    return;
  }

  if (_controller_list.size() == 1 && !_controller_list[0].has_joystick()) {
    _controller_list[0].add_joystick(joystick_id);
  } else {
    _controller_list.push_back(create_new_controller(joystick_id, false));
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
      _controller_list.push_back(create_new_controller(true));
    }
  }
}
