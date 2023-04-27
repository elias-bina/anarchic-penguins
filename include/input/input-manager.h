#ifndef _AN_PEN_INPUT_INPUT_MANAGER_H_
#define _AN_PEN_INPUT_INPUT_MANAGER_H_

#include <vector>

#include "input/action-list.h"
#include "input/input-controller.h"

class InputManager {
private:
  std::vector<InputController> _controller_list;

  bool _is_keyboard_mapped;

  bool isActionTriggered(DigitalActionList action, uint32_t controller_index);
  bool isActionTriggered(AnalogActionList action, uint32_t controller_index);
  float getAnalogActionPosition(AnalogActionList action,
                                uint32_t controller_index);

public:
  InputManager();

  void connectJoystick(uint32_t joystick_id);
  void disconnectJoystick(uint32_t joystick_id);

  bool isGlobalActionTriggered(DigitalActionList action);
  bool isGlobalActionTriggered(AnalogActionList action);
};

#endif //_AN_PEN_INPUT_INPUT_MANAGER_H_