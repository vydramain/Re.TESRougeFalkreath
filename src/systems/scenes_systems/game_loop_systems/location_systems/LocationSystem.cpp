//
// Created by vydra on 15.07.2020.
//

#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

LocationSystem::LocationSystem() {
  name = nullptr;
  size_x = 0;
  size_y = 0;
  entities = nullptr;
}

LocationSystem::LocationSystem(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                               LocationsEntitiesSystem *input_entities_system) {
  name = input_name;
  size_x = input_size_x;
  size_y = input_size_y;
  entities = input_entities_system;
}

LocationSystem::~LocationSystem() {
  delete entities;
}

const char *LocationSystem::get_name() const {
  return name;
}

bool LocationSystem::is_story_over() {
  return end_of_story;
}

void LocationSystem::story_is_over() {
  end_of_story = true;
}

LocationsEntitiesSystem *LocationSystem::get_entities() {
  return entities;
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

void LocationSystem::set_location(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                                  LocationsEntitiesSystem *input_entities_system) {
  name = input_name;
  size_x = input_size_x;
  size_y = input_size_y;
  delete entities;
  entities = new LocationsEntitiesSystem(*input_entities_system);
}
