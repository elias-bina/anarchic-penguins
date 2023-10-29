#ifndef _AN_PEN_INPUT_INPUT_CONTROLLER_H_
#define _AN_PEN_INPUT_INPUT_CONTROLLER_H_

#include <memory>

class InputController;
#include "entities/player.h"

class InputController {
private:
  bool _is_keyboard_holder;
  int32_t _joystick_index;

public:
  explicit InputController(int32_t joystick_index, bool map_keyboard_to_this);
  explicit InputController(bool map_keyboard_to_this);

  ~InputController();

  void set_joystick(int32_t joystick_index);
  int32_t get_joystick_index();
  bool has_joystick();

  void give_keyboard();
  bool has_keyboard();
};

#endif //_AN_PEN_INPUT_INPUT_CONTROLLER_H_
