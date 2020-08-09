//
// Created by vydra on 15.07.2020.
//

#include "ecs/systems/location_system/LocationSystem.h"

LocationSystem::LocationSystem(const char *input_name, Area *input_area, SentientsSystem *input_races,
                               MagwehrsSystem *input_creatures, ItemsSystem *input_items) {
  current_area = input_area;
  current_items = input_items;
  current_races = input_races;
  current_creatures = input_creatures;
}

LocationSystem::~LocationSystem() {
  delete current_area;
  delete current_races;
  delete current_creatures;
  delete current_items;
}

Area *LocationSystem::get_area() const {
  return current_area;
}

SentientsSystem *LocationSystem::get_races() const {
  return current_races;
}

MagwehrsSystem *LocationSystem::get_creatures() const {
  return current_creatures;
}

ItemsSystem *LocationSystem::get_items() const {
  return current_items;
}
