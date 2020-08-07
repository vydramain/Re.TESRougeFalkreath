//
// Created by vydra on 8/3/20.
//

#include "ecs/systems/location_system/Races.h"

Races::Races(const unsigned input_count) {
  vec_races.reserve(input_count);
}

Races::~Races() {
  vec_races.clear();
}

void Races::put_player(Sentient *input_player) {
  vec_races.insert(vec_races.begin(), *input_player);
}

Sentient *Races::remove_player() {
  Sentient *pointer = vec_races.data();
  auto *returning_player = new Sentient(pointer[0]);
  vec_races.erase(vec_races.begin());
  return returning_player;
}

void Races::put_race(Sentient *input_race) {
  vec_races.push_back(*input_race);
}

Sentient *Races::remove_race(unsigned int input_index) {
  Sentient *pointer = vec_races.data();
  auto *returning_race = new Sentient(pointer[input_index]);
  vec_races.erase(vec_races.begin() + input_index);
  return returning_race;
}

unsigned Races::get_size() const {
  return vec_races.size();
}

Sentient *Races::get_player() {
  return &vec_races[0];
}

Sentient *Races::get_race(const unsigned int input_index) {
  return &vec_races[input_index];
}

const Sentient *Races::get_player() const {
  const Sentient *pointer = &vec_races[0];
  return pointer;
}

const Sentient *Races::get_race(const unsigned int input_index) const {
  const Sentient *pointer = vec_races.data();
  return &pointer[input_index];
}
