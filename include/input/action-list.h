#ifndef _AN_PEN_INPUT_ACTION_LIST_H_
#define _AN_PEN_INPUT_ACTION_LIST_H_

#include <bitset>

enum class AnalogActionState
{
  PRIMARY_LEFT,
  PRIMARY_RIGHT,
  PRIMARY_UP,
  PRIMARY_DOWN,

  SECONDARY_LEFT,
  SECONDARY_RIGHT,
  SECONDARY_UP,
  SECONDARY_DOWN,

  LEFT_TRIGGER,
  RIGHT_TRIGGER,
  ENUM_LEN
};

class AnalogActionStateList {
public:
  AnalogActionStateList() = default;

private:
  float states[(unsigned int)AnalogActionState::ENUM_LEN];
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

private:
  std::bitset<(size_t)AnalogActionState::ENUM_LEN> states;
};

#endif //_AN_PEN_INPUT_ACTION_LIST_H_
