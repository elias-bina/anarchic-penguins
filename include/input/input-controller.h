#ifndef _AN_PEN_INPUT_INPUT_CONTROLLER_H_
#define _AN_PEN_INPUT_INPUT_CONTROLLER_H_

#include <memory>

#include "input/action-list.h"


constexpr int32_t UNDEFINED_INDEX = -1;

class InputController {
private:
  int32_t _joystick_index;

  bool _is_keyboard_holder;
  bool _has_player;

  AnalogActionStateList _analog_actions;
  DigitalActionStateList _digital_actions;


public:
  explicit InputController(int32_t joystick_index, bool map_keyboard_to_this);
  explicit InputController(bool map_keyboard_to_this);
  InputController();

  ~InputController();

  void set_joystick(int32_t joystick_index);
  int32_t get_joystick_index();
  bool has_joystick();

  void set_player();
  void remove_player();
  bool has_player();

  void give_keyboard();
  void remove_keyboard();
  bool has_keyboard();

  sf::Vector2f get_vector_move();
};

#endif //_AN_PEN_INPUT_INPUT_CONTROLLER_H_
