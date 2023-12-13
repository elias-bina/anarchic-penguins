#ifndef _AN_PEN_ENTITIES_PLAYER
#define _AN_PEN_ENTITIES_PLAYER

#include <SFML/System.hpp>

#include <mutex>
#include <random>

#include "entities/movable-entity.h"
#include "input/input-controller.h"


class Player : public MovableEntity {
private:
  InputController *_controller;

  sf::Vector2f _move_direction;

  std::mutex *_controller_mutex;

public:
  Player();
  ~Player();

  void Update(std::chrono::nanoseconds duration) override;

  void move_x_pixels(float pos);
  void move_y_pixels(float pos);
  void move_at_random(std::chrono::nanoseconds duration);

  void set_input_controller(InputController *controller);
  void unset_input_controller();

  bool has_controller();
  bool check_controller(InputController *controller);

  std::mt19937 gen;
  std::uniform_int_distribution<> distrib;

  int choice = 0;
  std::chrono::time_point<std::chrono::steady_clock> last_move_choice;
};

#endif //_AN_PEN_ENTITIES_PLAYER
