//
// Created by vydra on 16.07.2020.
//

#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/MagwehrsSystem.h"

MagwehrsSystem::MagwehrsSystem() = default;

MagwehrsSystem::~MagwehrsSystem() {
  for (auto &magwehr : magwehrs) {
    delete magwehr;
  }
}

void MagwehrsSystem::put_magwehr(Magwehr *input_creature) {
  magwehrs.insert(magwehrs.end(), input_creature);
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

int MagwehrsSystem::get_magwehr_index(unsigned int input_x, unsigned int input_y) {
  for (unsigned int i = 0; i < magwehrs.size(); i++) {
    if (magwehrs[i]->get_current_x() == input_x && magwehrs[i]->get_current_y() == input_y) {
      return i;
    }
  }
  return -1;
}

Magwehr *MagwehrsSystem::get_magwehr(const unsigned int input_index) {
  return magwehrs[input_index];
}


const Magwehr *MagwehrsSystem::get_magwehr(const unsigned int input_index) const {
  const Magwehr *pointer = magwehrs[input_index];
  return pointer;
}
