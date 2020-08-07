//
// Created by vydra on 16.07.2020.
//

#include "ecs/systems/location_system/Creatures.h"

#include <vector>

Creatures::Creatures(const unsigned input_count) {
  vec_creatures.reserve(input_count);
}

Creatures::~Creatures() {
  vec_creatures.clear();
}

void Creatures::put_creature(Magwehr *input_creature) {
  vec_creatures.push_back(*input_creature);
}

Magwehr *Creatures::remove_creature(unsigned int input_index) {
  Magwehr *pointer = vec_creatures.data();
  auto *returning_creature = new Magwehr(pointer[input_index]);
  vec_creatures.erase(vec_creatures.begin() + input_index);
  return returning_creature;
}

unsigned Creatures::get_size() const {
  return vec_creatures.size();
}

Magwehr *Creatures::get_creature(const unsigned int input_index) {
  return &vec_creatures[input_index];
}

const Magwehr *Creatures::get_creature(const unsigned int input_index) const {
  const Magwehr *pointer = vec_creatures.data();
  return &pointer[input_index];
}
