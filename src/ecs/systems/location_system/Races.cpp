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

void Races::put_player(Race *input_player) {
  vec_races.insert(vec_races.begin(), *input_player);
}

Race *Races::remove_player() {
  Race *pointer = vec_races.data();
  auto *returning_player = new Race(pointer[0]);
  vec_races.erase(vec_races.begin());
  return returning_player;
}

void Races::put_race(Race *input_race) {
  vec_races.push_back(*input_race);
}

Race *Races::remove_race(unsigned int input_index) {
  Race *pointer = vec_races.data();
  auto *returning_race = new Race(pointer[input_index]);
  vec_races.erase(vec_races.begin() + input_index);
  return returning_race;
}

unsigned Races::get_size() const {
  return vec_races.size();
}

Race *Races::get_player() {
  return &vec_races[0];
}

Race *Races::get_race(const unsigned int input_index) {
  return &vec_races[input_index];
}

const Race *Races::get_player() const {
  const Race *pointer = &vec_races[0];
  return pointer;
}

const Race *Races::get_race(const unsigned int input_index) const {
  const Race *pointer = vec_races.data();
  return &pointer[input_index];
}
