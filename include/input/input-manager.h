#ifndef _AN_PEN_INPUT_INPUT_MANAGER_H_
#define _AN_PEN_INPUT_INPUT_MANAGER_H_

#include <vector>

#include "input/action-list.h"
#include "input/input-controller.h"

enum NewPlayerChoice {
  PREVIOUS_PLAYER,
  NEXT_PLAYER,
  RANDOM_PLAYER
};

class InputManager {
private:
  std::shared_ptr<Player> get_free_player(NewPlayerChoice player_choice, uint32_t player_index);
  InputController create_new_controller(uint32_t controller_index, bool map_keyboard_to_this);
  InputController create_new_controller(bool map_keyboard_to_this);

  bool isActionTriggered(DigitalActionList action, uint32_t controller_index);
  bool isActionTriggered(AnalogActionList action, uint32_t controller_index);
  float getAnalogActionPosition(AnalogActionList action, uint32_t controller_index);

  std::vector<InputController> _controller_list;
  std::vector<std::shared_ptr<Player>> &_player_list;

  bool _is_keyboard_mapped;

public:
  explicit InputManager(std::vector<std::shared_ptr<Player>> &player_list);

  void connectJoystick(uint32_t joystick_id);
  void disconnectJoystick(uint32_t joystick_id);

  bool isGlobalActionTriggered(DigitalActionList action);
  bool isGlobalActionTriggered(AnalogActionList action);
};

#endif //_AN_PEN_INPUT_INPUT_MANAGER_H_
