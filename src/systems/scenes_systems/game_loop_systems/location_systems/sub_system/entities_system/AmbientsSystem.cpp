//
// Created by vydra on 8/14/20.
//

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/AmbientsSystem.h"

AmbientsSystem::AmbientsSystem() = default;

AmbientsSystem::~AmbientsSystem() {
  for (auto & ambient : ambients) {
    delete ambient;
  }
}

unsigned AmbientsSystem::get_ambients_size() const {
  return ambients.size();
}

int AmbientsSystem::get_ambient_index(Ambient *input_ambient) {
  for (unsigned int i = 0; i < ambients.size(); i++) {
    if (*ambients[i] == *input_ambient) {
      return i;
    }
  }
  return -1;
}

int AmbientsSystem::get_ambient_index(unsigned int input_x, unsigned int input_y) {
  for (unsigned int i = 0; i < ambients.size(); i++) {
    if (ambients[i]->get_current_x() == input_x && ambients[i]->get_current_y() == input_y) {
      return i;
    }
  }
  return -1;
}

Ambient *AmbientsSystem::get_ambient(unsigned int input_index) {
  return ambients[input_index];
}

const Ambient *AmbientsSystem::get_ambient(unsigned int input_index) const {
  const Ambient *pointer = ambients[input_index];
  return pointer;
}

void AmbientsSystem::put_ambient(Ambient *input_ambient) {
  ambients.insert(ambients.end(), input_ambient);
}

Ambient *AmbientsSystem::remove_ambient(unsigned int input_index) {
  Ambient *returning_ambient = ambients[input_index];
  ambients.erase(ambients.begin() + input_index);
  return returning_ambient;
}
