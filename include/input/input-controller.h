#ifndef _AN_PEN_INPUT_INPUT_CONTROLLER_H_
#define _AN_PEN_INPUT_INPUT_CONTROLLER_H_

#include <memory>

class InputController;
#include "entities/player.h"

class InputController {
private:
  std::shared_ptr<Player> _controlled_player;

  bool _is_keyboard_holder;
  int32_t _joystick_index;

public:
  explicit InputController(int32_t joystick_index, bool map_keyboard_to_this);
  explicit InputController(bool map_keyboard_to_this);

  void add_joystick(int32_t joystick_index);
  int32_t get_joystick_index();
  bool has_joystick();

  void give_keyboard();
  bool has_keyboard();

  void set_controlled_player(std::shared_ptr<Player> player);
};

#endif //_AN_PEN_INPUT_INPUT_CONTROLLER_H_
