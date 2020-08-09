//
// Created by vydra on 16.07.2020.
//

#include "ecs/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"

#include <vector>

MagwehrsSystem::MagwehrsSystem() = default;

MagwehrsSystem::~MagwehrsSystem() {
  magwehrs.clear();
}

void MagwehrsSystem::put_magwehr(Magwehr *input_creature) {
  magwehrs.push_back(input_creature);
}

Magwehr *MagwehrsSystem::remove_magwehr(unsigned int input_index) {
  Magwehr *returning_magwehr = magwehrs[input_index];
  magwehrs.erase(magwehrs.begin() + input_index);
  return returning_magwehr;
}

unsigned MagwehrsSystem::get_magwehrs_size() const {
  return magwehrs.size();
}

int MagwehrsSystem::get_magwehr_index(Magwehr *input_magwehr) {
  for (unsigned int i = 0; i < magwehrs.size(); i++) {
    if (*magwehrs[i] == *input_magwehr) {
      return i;
    }
  }
  return -1;
}

const Magwehr *MagwehrsSystem::get_magwehr(const unsigned int input_index) const {
  const Magwehr *pointer = magwehrs[input_index];
  return pointer;
}
