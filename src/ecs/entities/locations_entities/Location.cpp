//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/locations_entities/Location.h"

Location::Location(const char *input_name, Map *input_area, Creatures *input_creatures)
    : name(input_name), size_x(input_area->get_size_x()), size_y(input_area->get_size_y()) {
  current_area = input_area;
  current_creatures = input_creatures;
}

Location::~Location() {
  delete current_area;
  delete current_creatures;
}

const char *Location::get_name() const {
  return name;
}

unsigned int Location::get_size_x() const {
  return size_x;
}

unsigned int Location::get_size_y() const {
  return size_y;
}

Map *Location::get_current_area() const {
  return current_area;
}

Creatures *Location::get_current_creatures() const {
  return current_creatures;
}

void Location::set_name(const char *input_name) {
  Location::name = input_name;
}

void Location::set_current_area(Map *input_area) {
  current_area = input_area;
}

void Location::set_current_creatures(Creatures *input_creatures) {
  current_creatures = input_creatures;
}
