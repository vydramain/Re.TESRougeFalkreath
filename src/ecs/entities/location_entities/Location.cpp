//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/location_enities/Location.h"

Location::Location(const char *input_name, Area *input_area, Races *input_races, Creatures *input_creatures,
                   Items *input_items)
    : Entity(input_name) {
  current_area = input_area;
  current_items = input_items;
  current_races = input_races;
  current_creatures = input_creatures;
}

Location::~Location() {
  delete current_area;
  delete current_races;
  delete current_creatures;
  delete current_items;
}

Area *Location::get_area() const {
  return current_area;
}

Races *Location::get_races() const {
  return current_races;
}

Creatures *Location::get_creatures() const {
  return current_creatures;
}

Items *Location::get_items() const {
  return current_items;
}
