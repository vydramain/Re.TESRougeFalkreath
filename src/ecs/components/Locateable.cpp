//
// Created by vydra on 8/3/20.
//

#include "ecs/components/Locateable.h"

Locateable::Locateable(unsigned int input_x, unsigned int input_y) : current_x(input_x), current_y(input_y) {}

Locateable::~Locateable() {}

void Locateable::set_current_x(unsigned int input_x) {
  current_x = input_x;
}

void Locateable::set_current_y(unsigned int input_y) {
  current_y = input_y;
}

unsigned int Locateable::get_current_x() const {
  return current_x;
}

unsigned int Locateable::get_current_y() const {
  return current_y;
}
