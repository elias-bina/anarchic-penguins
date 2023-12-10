#include <criterion/criterion.h>
#include <random>

#include "input/input-manager.h"

static std::mt19937 gen;
static std::uniform_int_distribution<> distrib;

constexpr uint32_t MAX_SUPPORTED_CONTROLLER = 8;
constexpr size_t FUZZ_NB = 5;
constexpr size_t INPUT_COMBINATIONS_TESTED = 10;

Test(input_manager, default_state) {
  InputManager controller_manager{false};

  for (uint32_t controller_nb; controller_nb < MAX_SUPPORTED_CONTROLLER; controller_nb++) {
    cr_assert(controller_manager.controllerFromIndex(controller_nb) == nullptr);
  }
  cr_assert(controller_manager.controllerWithKeyboard() != nullptr);
  cr_assert(controller_manager.controllerWithKeyboard()->has_keyboard() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_joystick() == false);
  cr_assert(controller_manager.controllerWithKeyboard()->has_player() == false);
}


Test(input_manager, add_remove_single_controller) {
  InputManager controller_manager{false};

  auto joystick_choice = distrib(gen) % MAX_SUPPORTED_CONTROLLER;
  controller_manager.connectJoystick(joystick_choice);

  for (uint32_t controller_nb; controller_nb < MAX_SUPPORTED_CONTROLLER; controller_nb++) {
    if (controller_nb != joystick_choice)
      cr_assert(controller_manager.controllerFromIndex(controller_nb) == nullptr);
  }
  cr_assert(controller_manager.controllerFromIndex(joystick_choice) != nullptr);
  cr_assert(controller_manager.controllerFromIndex(joystick_choice)->has_keyboard() == true);
  cr_assert(controller_manager.controllerFromIndex(joystick_choice)->has_joystick() == true);
  cr_assert(controller_manager.controllerFromIndex(joystick_choice)->has_player() == false);

  cr_assert(controller_manager.controllerWithKeyboard() != nullptr);
  cr_assert(controller_manager.controllerWithKeyboard()->has_keyboard() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_joystick() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_player() == false);

  controller_manager.disconnectJoystick(joystick_choice);

  for (uint32_t controller_nb; controller_nb < MAX_SUPPORTED_CONTROLLER; controller_nb++) {
    cr_assert(controller_manager.controllerFromIndex(controller_nb) == nullptr);
  }

  cr_assert(controller_manager.controllerWithKeyboard() != nullptr);
  cr_assert(controller_manager.controllerWithKeyboard()->has_keyboard() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_joystick() == false);
  cr_assert(controller_manager.controllerWithKeyboard()->has_player() == false);
}

Test(input_manager, add_remove_multiple_controllers) {
  InputManager controller_manager{false};

  std::vector<uint32_t> connected_controllers;

  // Add multiple random controllers
  for (size_t i = 0; i < INPUT_COMBINATIONS_TESTED; i++) {
    uint32_t controller_nb = distrib(gen) % MAX_SUPPORTED_CONTROLLER;
    connected_controllers.push_back(controller_nb);
    controller_manager.connectJoystick(controller_nb);
  }

  // Verify that the added controllers are connected
  for (uint32_t controller_nb = 0; controller_nb < MAX_SUPPORTED_CONTROLLER; controller_nb++) {
    if (std::find(connected_controllers.begin(), connected_controllers.end(), controller_nb) !=
        connected_controllers.end()) {
      cr_assert(controller_manager.controllerFromIndex(controller_nb) != nullptr);
      cr_assert(controller_manager.controllerFromIndex(controller_nb)->has_joystick() == true);
      cr_assert(controller_manager.controllerFromIndex(controller_nb)->has_player() == false);
      if (*connected_controllers.begin() == controller_nb) {
        cr_assert(controller_manager.controllerFromIndex(controller_nb)->has_keyboard() == true);
      } else {
        cr_assert(controller_manager.controllerFromIndex(controller_nb)->has_keyboard() == false);
      }
    } else {
      cr_assert(controller_manager.controllerFromIndex(controller_nb) == nullptr);
    }
  }

  cr_assert(controller_manager.controllerWithKeyboard() != nullptr);
  cr_assert(controller_manager.controllerWithKeyboard()->has_keyboard() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_joystick() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_player() == false);

  // Remove the controllers in random order
  std::shuffle(connected_controllers.begin(), connected_controllers.end(), gen);
  for (uint32_t controller_nb : connected_controllers) {
    controller_manager.disconnectJoystick(controller_nb);
  }

  // Verify that all controllers are disconnected
  for (uint32_t controller_nb = 0; controller_nb < MAX_SUPPORTED_CONTROLLER; controller_nb++) {
    cr_assert(controller_manager.controllerFromIndex(controller_nb) == nullptr);
  }

  cr_assert(controller_manager.controllerWithKeyboard() != nullptr);
  cr_assert(controller_manager.controllerWithKeyboard()->has_keyboard() == true);
  cr_assert(controller_manager.controllerWithKeyboard()->has_joystick() == false);
  cr_assert(controller_manager.controllerWithKeyboard()->has_player() == false);
}

// Test(input_manager, add_remove_multiple_controllers) {
//   cr_assert(0);
// }
