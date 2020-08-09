//
// Created by vydra on 15.07.2020.
//

#include "ecs/systems/location_system/LocationSystem.h"

LocationSystem::LocationSystem(Area *input_area, LocationsEntitiesSystem *input_entites)
    : area(input_area), entities(input_entites) {}

LocationSystem::~LocationSystem() {
  delete area;
  delete entities;
}

Area *LocationSystem::get_area() const {
  return area;
}

LocationsEntitiesSystem *LocationSystem::get_entities() const {
  return entities;
}
