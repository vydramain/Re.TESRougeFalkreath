//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_ENTITIES_RACES_ENTITIES_RACE_H_
#define INCLUDE_ECS_ENTITIES_RACES_ENTITIES_RACE_H_

#include "ecs/components/Pocket.h"

class Race : public Pocket {
 private:
  const char *name;
  unsigned current_x;
  unsigned current_y;
  unsigned sight_x;
  unsigned sight_y;

 private:
  enum direction {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_RIGHT,
    DIRECTION_LEFT,
  };

  direction current_direction;

 public:
  explicit Race(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0,
                unsigned input_pocket = 10, unsigned input_wallet = 0);
  Race(const Race &input_race);
  Race(Race &&input_race) noexcept;
  Race &operator=(const Race &input_race);
  Race &operator=(Race &&input_race) noexcept;

  const char *get_name() const;
  unsigned get_current_x() const;
  unsigned get_current_y() const;
  unsigned int get_sight_x() const;
  unsigned int get_sight_y() const;
  unsigned get_current_direction() const;

  void set_name(char *input_name);
  void set_current_x(unsigned int input_x);
  void set_current_y(unsigned int input_y);
  void set_current_direction(direction input_direction);
  void set_sight();

  /**
   * Methods for creatures moves on map
   * This method change creature's coordinates and change direction
   */
  void go_up();
  void go_down(unsigned input_border);
  void go_left();
  void go_right(unsigned input_border);
};

#endif  // INCLUDE_ECS_ENTITIES_RACES_ENTITIES_RACE_H_
