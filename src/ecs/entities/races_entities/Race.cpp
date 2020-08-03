//
// Created by vydra on 8/3/20.
//

#include "ecs/entities/races_entities/Race.h"

Race::Race(const char *input_name, const unsigned input_current_x, const unsigned input_current_y,
           const unsigned input_pocket)
    : Pocket(input_pocket),
      name(input_name),
      current_x(input_current_x),
      current_y(input_current_y),
      current_direction(DIRECTION_LEFT) {}

Race::Race(const Race &input_creature)
    : Pocket(input_creature.get_pocket_size()),
      name(input_creature.name),
      current_x(input_creature.current_x),
      current_y(input_creature.current_y),
      current_direction(input_creature.current_direction) {}

Race::Race(Race &&input_creature) noexcept
    : Pocket(input_creature.get_pocket_size()),
      name(input_creature.name),
      current_x(input_creature.current_x),
      current_y(input_creature.current_y),
      current_direction(input_creature.current_direction) {}

Race &Race::operator=(const Race &input_creature) {
  name = input_creature.get_name();
  current_x = input_creature.get_current_x();
  current_y = input_creature.get_current_y();
  current_direction = input_creature.current_direction;
  clear_pocket();
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(*input_creature.get_item(i));
  }
  return *this;
}

Race &Race::operator=(Race &&input_creature) noexcept {
  name = input_creature.get_name();
  current_x = input_creature.get_current_x();
  current_y = input_creature.get_current_y();
  current_direction = input_creature.current_direction;
  clear_pocket();
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(*input_creature.get_item(i));
  }
  return *this;
}

const char *Race::get_name() const {
  return name;
}

unsigned int Race::get_current_x() const {
  return current_x;
}

unsigned int Race::get_current_y() const {
  return current_y;
}

unsigned int Race::get_sight_x() const {
  return sight_x;
}
unsigned int Race::get_sight_y() const {
  return sight_y;
}

unsigned Race::get_current_direction() const {
  return current_direction;
}

void Race::set_name(char *input_name) {
  name = input_name;
}

void Race::set_current_x(unsigned int input_x) {
  current_x = input_x;
}

void Race::set_current_y(unsigned int input_y) {
  current_y = input_y;
}

void Race::set_current_direction(direction input_direction) {
  current_direction = input_direction;
}

void Race::set_sight() {
  sight_x = current_x;
  sight_y = current_y;
  switch (current_direction) {
    case DIRECTION_UP:
      sight_y--;
      break;
    case DIRECTION_DOWN:
      sight_y++;
      break;
    case DIRECTION_RIGHT:
      sight_x++;
      break;
    case DIRECTION_LEFT:
      sight_x--;
      break;
    default:
      break;
  }
}

void Race::go_up() {
  current_direction = DIRECTION_UP;
  if (current_y > 0) {
    current_y--;
  }
  set_sight();
}

void Race::go_down(const unsigned input_border) {
  current_direction = DIRECTION_DOWN;
  if (current_y + 1 < input_border) {
    current_y++;
  }
  set_sight();
}
void Race::go_left() {
  current_direction = DIRECTION_LEFT;
  if (current_x > 0) {
    current_x--;
  }
  set_sight();
}
void Race::go_right(const unsigned input_border) {
  current_direction = DIRECTION_RIGHT;
  if (current_x + 1 < input_border) {
    current_x++;
  }
  set_sight();
}
