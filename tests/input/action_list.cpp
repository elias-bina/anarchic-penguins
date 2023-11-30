#include <iostream>
#include <random>
#include <set>

#include <criterion/criterion.h>

#include "input/action-list.h"
#include "input/input-controller.h"
#include "input/input-manager.h"

std::mt19937 gen;
std::uniform_int_distribution<> distrib;

constexpr size_t FUZZ_NB = 5;
constexpr size_t INPUT_COMBINATIONS_TESTED = 10;

Test(analog_actions, list_default_state) {
  AnalogActionStateList analog_list;

  cr_assert(analog_list.get_primary_state() == sf::Vector2f(0.0f, 0.0f));
  cr_assert(analog_list.get_secondary_state() == sf::Vector2f(0.0f, 0.0f));
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal")
  cr_assert(analog_list.get_trigger(AnalogActionState::LEFT_TRIGGER) == -0.0f);
  cr_assert(analog_list.get_trigger(AnalogActionState::RIGHT_TRIGGER) == 0.0f);
#pragma GCC diagnostic pop
}


Test(analog_actions, list_wrong_trigger) {
  AnalogActionStateList analog_list;
  cr_assert_throw(analog_list.get_trigger(AnalogActionState::PRIMARY_HORIZONTAL), std::invalid_argument);
  cr_assert_throw(analog_list.get_trigger(AnalogActionState::SECONDARY_HORIZONTAL), std::invalid_argument);
  cr_assert_throw(analog_list.get_trigger(AnalogActionState::PRIMARY_VERTICAL), std::invalid_argument);
  cr_assert_throw(analog_list.get_trigger(AnalogActionState::SECONDARY_VERTICAL), std::invalid_argument);
}

Test(analog_actions, list_set_axis) {
  AnalogActionStateList analog_list;

  analog_list.set_axis_value(AnalogActionState::PRIMARY_VERTICAL, 1.0f);
  cr_assert(analog_list.get_primary_state() == sf::Vector2f(0.0f, 1.0f));
  analog_list.set_axis_value(AnalogActionState::PRIMARY_VERTICAL, 0.0f);
  analog_list.set_axis_value(AnalogActionState::PRIMARY_HORIZONTAL, 1.0f);
  cr_assert(analog_list.get_primary_state() == sf::Vector2f(1.0f, 0.0f));

  analog_list.set_axis_value(AnalogActionState::SECONDARY_VERTICAL, 1.0f);
  cr_assert(analog_list.get_secondary_state() == sf::Vector2f(0.0f, 1.0f));
  analog_list.set_axis_value(AnalogActionState::SECONDARY_VERTICAL, 0.0f);
  analog_list.set_axis_value(AnalogActionState::SECONDARY_HORIZONTAL, 1.0f);
  cr_assert(analog_list.get_secondary_state() == sf::Vector2f(1.0f, 0.0f));

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal")
  analog_list.set_axis_value(AnalogActionState::LEFT_TRIGGER, 1.0f);
  cr_assert(analog_list.get_trigger(AnalogActionState::LEFT_TRIGGER) == 1.0f);
  analog_list.set_axis_value(AnalogActionState::RIGHT_TRIGGER, 1.0f);
  cr_assert(analog_list.get_trigger(AnalogActionState::RIGHT_TRIGGER) == 1.0f);
#pragma GCC diagnostic pop
}

Test(analog_actions, list_check_norm) {
  AnalogActionStateList analog_list;

  // Primary

  analog_list.set_axis_value(AnalogActionState::PRIMARY_VERTICAL, 1.0f);
  analog_list.set_axis_value(AnalogActionState::PRIMARY_HORIZONTAL, 1.0f);
  cr_assert(analog_list.get_primary_state().x < 1.0f);
  cr_assert(analog_list.get_primary_state().y < 1.0f);


  analog_list.set_axis_value(AnalogActionState::PRIMARY_HORIZONTAL, 0.0f);
  cr_assert(analog_list.get_primary_state() == sf::Vector2f(0.0f, 1.0f));

  analog_list.set_axis_value(AnalogActionState::PRIMARY_HORIZONTAL, -1.0f);
  cr_assert(analog_list.get_primary_state().x > -1.0f);
  cr_assert(analog_list.get_primary_state().y < 1.0f);


  analog_list.set_axis_value(AnalogActionState::PRIMARY_VERTICAL, 0.0f);
  cr_assert(analog_list.get_primary_state() == sf::Vector2f(-1.0f, 0.0f));

  // Secondary

  analog_list.set_axis_value(AnalogActionState::SECONDARY_VERTICAL, 1.0f);
  analog_list.set_axis_value(AnalogActionState::SECONDARY_HORIZONTAL, 1.0f);
  cr_assert(analog_list.get_secondary_state().x < 1.0f);
  cr_assert(analog_list.get_secondary_state().y < 1.0f);


  analog_list.set_axis_value(AnalogActionState::SECONDARY_HORIZONTAL, 0.0f);
  cr_assert(analog_list.get_secondary_state() == sf::Vector2f(0.0f, 1.0f));

  analog_list.set_axis_value(AnalogActionState::SECONDARY_HORIZONTAL, -1.0f);
  cr_assert(analog_list.get_secondary_state().x > -1.0f);
  cr_assert(analog_list.get_secondary_state().y < 1.0f);


  analog_list.set_axis_value(AnalogActionState::SECONDARY_VERTICAL, 0.0f);
  cr_assert(analog_list.get_secondary_state() == sf::Vector2f(-1.0f, 0.0f));
}


Test(digital_actions, list_default_state) {
  DigitalActionStateList digital_list;
  for (DigitalActionState button = DigitalActionState::MAP_ACTION; button < DigitalActionState::ENUM_LEN; button++)
    cr_assert(digital_list.get_button_value(button) == false);
}

Test(digital_actions, list_fail_on_last) {
  DigitalActionStateList digital_list;
  cr_assert_throw(digital_list.set_button_value(DigitalActionState::ENUM_LEN, true), std::out_of_range);
}

Test(digital_actions, list_fuzz_multiple_set) {
  DigitalActionStateList digital_list;

  for (size_t i = 0; i < FUZZ_NB; i++) {
    std::set<DigitalActionState> tested_actions;
    std::vector<DigitalActionState> all_actions;
    for (DigitalActionState button = DigitalActionState::MAP_ACTION; button < DigitalActionState::ENUM_LEN; button++)
      all_actions.push_back(button);

    for (size_t j = 0; j < INPUT_COMBINATIONS_TESTED; j++) {
      auto choice = distrib(gen) % all_actions.size();
      tested_actions.insert(all_actions[choice]);
      all_actions.erase(all_actions.begin() + choice);

      for (DigitalActionState button = DigitalActionState::MAP_ACTION; button < DigitalActionState::ENUM_LEN; button++)
        cr_assert(digital_list.get_button_value(button) == false);

      for (DigitalActionState elem : tested_actions)
        digital_list.set_button_value(elem, true);

      for (DigitalActionState button = DigitalActionState::MAP_ACTION; button < DigitalActionState::ENUM_LEN;
           button++) {
        if (tested_actions.find(button) != tested_actions.end()) {
          cr_assert(digital_list.get_button_value(button) == true);
        } else {
          cr_assert(digital_list.get_button_value(button) == false);
        }
      }

      for (DigitalActionState elem : tested_actions)
        digital_list.set_button_value(elem, false);
    }
    tested_actions.clear();
    all_actions.clear();
  }
}
