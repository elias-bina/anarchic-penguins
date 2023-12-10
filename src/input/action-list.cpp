
#include <cmath>
#include <iostream>

#include "input/action-list.h"

AnalogActionStateList::AnalogActionStateList() : _left_trigger{0.0f}, _right_trigger{0.0f} {}

void AnalogActionStateList::set_axis_value(AnalogActionState axis, float value) {
  switch (axis) {
  case AnalogActionState::PRIMARY_HORIZONTAL:
    _primary_state.x = value;
    break;
  case AnalogActionState::PRIMARY_VERTICAL:
    _primary_state.y = value;
    break;

  case AnalogActionState::SECONDARY_HORIZONTAL:
    _secondary_state.x = value;
    break;
  case AnalogActionState::SECONDARY_VERTICAL:
    _secondary_state.y = value;
    break;

  case AnalogActionState::LEFT_TRIGGER:
    _left_trigger = value;
    break;
  case AnalogActionState::RIGHT_TRIGGER:
    _right_trigger = value;
    break;
  }
}

static sf::Vector2f normalize_on_treshold(sf::Vector2f vector, float squared_treshold) {
  float squared_norm = (float)(std::pow(vector.x, 2) + std::pow(vector.y, 2));
  if (squared_norm <= squared_treshold)
    return vector;
  return vector / std::sqrt(squared_norm);
}

sf::Vector2f AnalogActionStateList::get_primary_state() { return normalize_on_treshold(_primary_state, 1.0); }

sf::Vector2f AnalogActionStateList::get_secondary_state() { return normalize_on_treshold(_secondary_state, 1.0); }

float AnalogActionStateList::get_raw_axis(AnalogActionState axis) {
  switch (axis) {
  case AnalogActionState::PRIMARY_HORIZONTAL:
    return _primary_state.x;
    break;
  case AnalogActionState::PRIMARY_VERTICAL:
    return _primary_state.y;
    break;

  case AnalogActionState::SECONDARY_HORIZONTAL:
    return _secondary_state.x;
    break;
  case AnalogActionState::SECONDARY_VERTICAL:
    return _secondary_state.y;
    break;

  default:
    throw std::invalid_argument{"I asked for an axiiiiiiiiiiiiis"};
    break;
  }
}

float AnalogActionStateList::get_trigger(AnalogActionState trigger) {
  switch (trigger) {
  case AnalogActionState::LEFT_TRIGGER:
    return _left_trigger;
    break;
  case AnalogActionState::RIGHT_TRIGGER:
    return _right_trigger;
    break;

  default:
    throw std::invalid_argument{"I asked for a triggeeeeeeeeeeeeeeeeeeer"};
    break;
  }
}

void DigitalActionStateList::set_button_value(DigitalActionState button, bool value) {
  if (button == DigitalActionState::ENUM_LEN)
    throw std::out_of_range{"This is not a real action you stupid"};
  _states.set((size_t)button, value);
}

bool DigitalActionStateList::get_button_value(DigitalActionState button) { return _states[(size_t)button]; }
