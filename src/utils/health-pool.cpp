
#include <stdexcept>

#include "utils/health-pool.h"


HealthPool::HealthPool() : HealthPool{0, false} {}
HealthPool::HealthPool(int32_t max_hp) : HealthPool{max_hp, true} {}
HealthPool::HealthPool(int32_t max_hp, bool killable) : _killable{killable}, _max_hp{max_hp}, _current_hp{max_hp} {}

// Returns true if the entity is still alive
bool HealthPool::take_damage(int32_t damage) {
  if (damage < 0) {
    throw std::invalid_argument("Cannot take negative damage");
  }
  _current_hp -= damage;
  return is_alive();
}

// Returns true if all heal was applied
bool HealthPool::heal_damage(int32_t heal) {
  if (heal < 0) {
    throw std::invalid_argument("Cannot heal negative damage");
  }
  _current_hp += heal;
  if (_current_hp > _max_hp) {
    _current_hp = _max_hp;
    return false;
  }
  return true;
}

bool HealthPool::is_alive() const { return !_killable || _current_hp > 0; }
bool HealthPool::is_killable() const { return _killable; }
int32_t HealthPool::get_current_hp() const { return _current_hp; }
int32_t HealthPool::get_max_hp() const { return _max_hp; }
