//
// Created by vydra on 8/3/20.
//

#include "ecs/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

SentientsSystem::SentientsSystem(const unsigned input_count) {
  sentients.reserve(input_count);
}

SentientsSystem::~SentientsSystem() {
  sentients.clear();
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
  sentients.push_back(input_sentient);
}

Sentient *SentientsSystem::remove_sentient(unsigned int input_index) {
  Sentient *returning_sentient = sentients[input_index];
  sentients[input_index] = nullptr;
  sentients.erase(sentients.begin() + input_index);
  return returning_sentient;
}

unsigned SentientsSystem::get_size() const {
  return sentients.size();
}

Sentient *SentientsSystem::get_player() {
  return sentients[0];
}

Sentient *SentientsSystem::get_sentient(const unsigned int input_index) {
  return sentients[input_index];
}

const Sentient *SentientsSystem::get_player() const {
  const Sentient *pointer = sentients[0];
  return pointer;
}

const Sentient *SentientsSystem::get_sentient(const unsigned int input_index) const {
  const Sentient *pointer = sentients[input_index];
  return pointer;
}
