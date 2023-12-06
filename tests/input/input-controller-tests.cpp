#include <criterion/criterion.h>

#include "input/input-controller.h"

Test(input_controller, default_state) {
  InputController controller;

  cr_assert(controller.get_joystick_index() == UNDEFINED_INDEX);
  cr_assert(!controller.has_joystick());
  cr_assert(!controller.has_player());
  cr_assert(!controller.has_keyboard());
  cr_assert(controller.get_vector_move() == sf::Vector2f(0.0f, 0.0f));
  cr_assert(controller.get_vector_camera() == sf::Vector2f(0.0f, 0.0f));
}

// Test(input_controller, set_values) {
//   InputController controller;

//   cr_assert(0);
// cr_assert(controller.get_joystick_index() == UNDEFINED_INDEX);
// cr_assert(!controller.has_joystick());
// cr_assert(!controller.has_player());
// cr_assert(!controller.has_keyboard());
// cr_assert(controller.get_vector_move() == sf::Vector2f(0.0f, 0.0f));
// }

// TODO: Check that keyboard_input fails if no keyboard
//        same for joystick
