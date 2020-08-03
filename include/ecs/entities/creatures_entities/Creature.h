//
// Created by vydra on 15.07.2020.
//

#ifndef INCLUDE_ECS_ENTITIES_CREATURES_ENTITIES_CREATURE_H_
#define INCLUDE_ECS_ENTITIES_CREATURES_ENTITIES_CREATURE_H_

class Creature {
 private:
  const char *name;
  unsigned current_x;
  unsigned current_y;

  enum direction {
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_RIGHT,
    DIRECTION_LEFT,
  };

  direction current_direction;

 public:
  explicit Creature(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0);
  Creature(const Creature &input_creature);

  const char *get_name() const;
  unsigned get_current_x() const;
  unsigned get_current_y() const;
  unsigned get_current_direction() const;

  void set_name(char *input_name);
  void set_current_x(unsigned int input_x);
  void set_current_y(unsigned int input_y);
  void set_current_direction(direction input_direction);

  /**
   * Methods for creatures moves on map
   * This method change creature's coordinates and change direction
   */
  void go_up();
  void go_down(unsigned input_border);
  void go_left();
  void go_right(unsigned input_border);
};

#endif  // INCLUDE_ECS_ENTITIES_CREATURES_ENTITIES_CREATURE_H_
