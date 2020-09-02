//
// Created by vydra on 8/3/20.
//

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/SentientsSystem.h"

SentientsSystem::SentientsSystem() = default;

SentientsSystem::~SentientsSystem() {
  for (auto &sentient : sentients) {
    delete sentient;
  }
}

void SentientsSystem::put_player(Sentient *input_player) {
  sentients.insert(sentients.begin(), input_player);
}

Sentient *SentientsSystem::remove_player() {
  Sentient *returning_player = sentients[0];
  sentients[0] = nullptr;
  return returning_player;
}

void SentientsSystem::put_sentient(Sentient *input_sentient) {
  sentients.insert(sentients.end(), input_sentient);
}

Sentient *SentientsSystem::remove_sentient(unsigned int input_index) {
  Sentient *returning_sentient = sentients[input_index];
  sentients[input_index] = nullptr;
  sentients.erase(sentients.begin() + input_index);
  return returning_sentient;
}

unsigned SentientsSystem::get_sentients_size() const {
  return sentients.size();
}

Sentient *SentientsSystem::get_player() {
  return sentients[0];
}

Sentient *SentientsSystem::get_sentient(const unsigned int input_index) {
  return sentients[input_index];
}

int SentientsSystem::get_sentient_index(Sentient *input_magwehr) {
  for (unsigned int i = 0; i < sentients.size(); i++) {
    if (*sentients[i] == *input_magwehr) {
      return i;
    }
  }
  return -1;
}

const Sentient *SentientsSystem::get_sentient(const unsigned int input_index) const {
  const Sentient *pointer = sentients[input_index];
  return pointer;
}
