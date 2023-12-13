#ifndef __AN_PEN_UTILS_HEALTHPOOL_H__
#define __AN_PEN_UTILS_HEALTHPOOL_H__

#include <cstdint>

class HealthPool {
public:
  explicit HealthPool();
  explicit HealthPool(int32_t max_hp);
  explicit HealthPool(int32_t max_hp, bool killable);

  bool take_damage(int32_t damage);
  bool heal_damage(int32_t heal);

  bool is_alive() const;
  bool is_killable() const;

  int32_t get_current_hp() const;
  int32_t get_max_hp() const;

private:
  bool _killable;

  int32_t _max_hp;
  int32_t _current_hp;
};

#endif //__AN_PEN_UTILS_HEALTHPOOL_H__
