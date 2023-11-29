#ifndef _AN_PEN_INPUT_ACTION_LIST_H_
#define _AN_PEN_INPUT_ACTION_LIST_H_

#include <bitset>

#include <SFML/System/Vector2.hpp>

enum class AnalogActionState
{
  PRIMARY_HORIZONTAL,
  PRIMARY_VERTICAL,

  SECONDARY_HORIZONTAL,
  SECONDARY_VERTICAL,

  LEFT_TRIGGER,
  RIGHT_TRIGGER,
};

class AnalogActionStateList {
public:
  AnalogActionStateList() = default;

  void set_axis_value(AnalogActionState axis, float value);

  sf::Vector2f get_primary_state();
  sf::Vector2f get_secondary_state();
  float get_trigger(AnalogActionState trigger);


private:
  sf::Vector2f _primary_state;
  sf::Vector2f _secondary_state;
  float _left_trigger;
  float _right_trigger;
};

enum class DigitalActionState
{
  MAP_ACTION,
  PAUSE_ACTION,

  LEFT_BUTTON_ACTION,
  RIGHT_BUTTON_ACTION,

  A_BUTTON_ACTION,
  B_BUTTON_ACTION,
  X_BUTTON_ACTION,
  Y_BUTTON_ACTION,

  PRIMARY_LEFT_BUTTON,
  PRIMARY_RIGHT_BUTTON,
  PRIMARY_UP_BUTTON,
  PRIMARY_DOWN_BUTTON,

  PRIMARY_JOY_CLICK,
  SECONDARY_JOY_CLICK,
  ENUM_LEN
};

class DigitalActionStateList {
public:
  DigitalActionStateList() = default;

  void set_button_value(DigitalActionState button, bool value);
  bool get_button_value(DigitalActionState button);

private:
  std::bitset<(size_t)DigitalActionState::ENUM_LEN> _states;
};

#endif //_AN_PEN_INPUT_ACTION_LIST_H_
