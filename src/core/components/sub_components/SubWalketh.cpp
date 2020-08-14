//
// Created by vydra on 8/7/20.
//

#include "core/components/sub_components/SubWalketh.hpp"

void SubWalketh::set_sight() {
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

SubWalketh::SubWalketh(unsigned int input_x, unsigned int input_y) : SubLocatable(input_x, input_y) {
  set_sight();
}

SubWalketh::~SubWalketh() {}

unsigned int SubWalketh::get_sight_x() const {
  return sight_x;
}

unsigned int SubWalketh::get_sight_y() const {
    return sight_y;
}

void SubWalketh::go_up() {
  current_direction = DIRECTION_UP;
  if (current_y > 0) {
    current_y--;
  }
  set_sight();
}

void SubWalketh::go_down(const unsigned input_border) {
  current_direction = DIRECTION_DOWN;
  if (current_y + 1 < input_border) {
    current_y++;
  }
  set_sight();
}

void SubWalketh::go_left() {
  current_direction = DIRECTION_LEFT;
  if (current_x > 0) {
    current_x--;
  }
  set_sight();
}

void SubWalketh::go_right(const unsigned input_border) {
  current_direction = DIRECTION_RIGHT;
  if (current_x + 1 < input_border) {
    current_x++;
  }
  set_sight();
}

void SubWalketh::look_up() {
  current_direction = DIRECTION_UP;
  set_sight();
}

void SubWalketh::look_down() {
  current_direction = DIRECTION_DOWN;
  set_sight();
}

void SubWalketh::look_left() {
  current_direction = DIRECTION_LEFT;
  set_sight();
}

void SubWalketh::look_right() {
  current_direction = DIRECTION_RIGHT;
  set_sight();
}
