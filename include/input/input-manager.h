#ifndef _AN_PEN_INPUT_INPUT_MANAGER_H_
#define _AN_PEN_INPUT_INPUT_MANAGER_H_

#include <unordered_map>

#include "input/action-list.h"
#include "input/input-controller.h"

// TODO: Define the actions detection
class InputManager {
private:
  bool isActionTriggered(DigitalActionState action, uint32_t controller_index);
  bool isActionTriggered(AnalogActionState action, uint32_t controller_index);
  float getAnalogActionPosition(AnalogActionState action, uint32_t controller_index);

  std::unordered_map<int32_t, InputController> _controller_list;

  bool _is_keyboard_mapped;

public:
  InputManager();

  void connectJoystick(uint32_t joystick_id);
  void disconnectJoystick(uint32_t joystick_id);

  InputController *controllerFromIndex(uint32_t controller_index);
  InputController *controllerWithKeyboard();

  bool isGlobalActionTriggered(DigitalActionState action);
  bool isGlobalActionTriggered(AnalogActionState action);
};

#endif //_AN_PEN_INPUT_INPUT_MANAGER_H_
