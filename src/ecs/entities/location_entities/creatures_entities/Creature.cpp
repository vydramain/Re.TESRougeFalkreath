//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/location_enities/creatures_entities/Creature.h"

Creature::Creature(const char *input_name, const unsigned input_current_x, const unsigned input_current_y)
    : name(input_name), current_x(input_current_x), current_y(input_current_y), current_direction(DIRECTION_LEFT) {}

Creature::Creature(const Creature &input_creature)
    : name(input_creature.name),
      current_x(input_creature.current_x),
      current_y(input_creature.current_y),
      current_direction(input_creature.current_direction) {}

Creature::Creature(Creature &&input_creature) noexcept
    : name(input_creature.name),
      current_x(input_creature.current_x),
      current_y(input_creature.current_y),
      current_direction(input_creature.current_direction) {}

Creature &Creature::operator=(const Creature &input_creature) {
  name = input_creature.get_name();
  current_x = input_creature.get_current_x();
  current_y = input_creature.get_current_y();
  current_direction = input_creature.current_direction;
  return *this;
}

Creature &Creature::operator=(Creature &&input_creature) noexcept {
  name = input_creature.get_name();
  current_x = input_creature.get_current_x();
  current_y = input_creature.get_current_y();
  current_direction = input_creature.current_direction;
  return *this;
}
const char *Creature::get_name() const {
  return name;
}

unsigned int Creature::get_current_x() const {
  return current_x;
}

unsigned int Creature::get_current_y() const {
  return current_y;
}

unsigned int Creature::getSightX() const {
  return sight_x;
}
unsigned int Creature::getSightY() const {
  return sight_y;
}

unsigned Creature::get_current_direction() const {
  return current_direction;
}

void Creature::set_name(char *input_name) {
  name = input_name;
}

void Creature::set_current_x(unsigned int input_x) {
  current_x = input_x;
}

void Creature::set_current_y(unsigned int input_y) {
  current_y = input_y;
}

void Creature::set_current_direction(direction input_direction) {
  current_direction = input_direction;
}

void Creature::set_sight() {
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

void Creature::go_up() {
  current_direction = DIRECTION_UP;
  if (current_y > 0) {
    current_y--;
  }
  set_sight();
}

void Creature::go_down(const unsigned input_border) {
  current_direction = DIRECTION_DOWN;
  if (current_y + 1 < input_border) {
    current_y++;
  }
  set_sight();
}
void Creature::go_left() {
  current_direction = DIRECTION_LEFT;
  if (current_x > 0) {
    current_x--;
  }
  set_sight();
}
void Creature::go_right(const unsigned input_border) {
  current_direction = DIRECTION_RIGHT;
  if (current_x + 1 < input_border) {
    current_x++;
  }
  set_sight();
}
