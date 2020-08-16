//
// Created by vydra on 15.07.2020.
//

#include "systems/location_systems/LocationSystem.h"

LocationSystem::LocationSystem(unsigned input_x, unsigned input_y, LocationsEntitiesSystem *input_entites)
    : size_x(input_x), size_y(input_y) {
  entities = new LocationsEntitiesSystem(*input_entites);
}

LocationSystem::~LocationSystem() {
  delete entities;
}

LocationsEntitiesSystem *LocationSystem::get_entities() const {
  return entities;
}

unsigned LocationSystem::get_size_x() const {
  return size_x;
}

unsigned LocationSystem::get_size_y() const {
  return size_y;
}
