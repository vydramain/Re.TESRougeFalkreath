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
                               EntitiesSystem *input_entities_system) {
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

void LocationSystem::set_go_to_bloodlet_throne_from_west_forest(bool input_boolean) {
  is_go_to_bloodlet_throne_from_west_forest = input_boolean;
}

void LocationSystem::set_go_to_west_forest_from_bloodlet_throne_by_hatch(bool input_boolean) {
  is_go_to_west_forest_from_bloodlet_throne_by_hatch = input_boolean;
}
void LocationSystem::set_go_to_west_forest_from_bloodlet_throne_by_cave(bool input_boolean) {
  is_go_to_west_forest_from_bloodlet_throne_by_cave = input_boolean;
}

void LocationSystem::set_go_to_falkreath_from_west_forest(bool input_boolean) {
  is_go_to_falkreath_from_west_forest = input_boolean;
}
void LocationSystem::set_go_to_west_forest_form_falkreth(bool input_boolean) {
  is_go_to_west_forest_from_falkreath = input_boolean;
}
void LocationSystem::set_story_end(bool input_boolean) {
  is_story_end = input_boolean;
}

bool LocationSystem::get_go_to_bloodlet_throne_from_west_forest() const {
  return is_go_to_bloodlet_throne_from_west_forest;
}

bool LocationSystem::get_go_to_west_forest_from_bloodlet_throne_by_hatch() const {
  return is_go_to_west_forest_from_bloodlet_throne_by_hatch;
}

bool LocationSystem::get_go_to_west_forest_from_bloodlet_throne_by_cave() const {
  return is_go_to_west_forest_from_bloodlet_throne_by_cave;
}

bool LocationSystem::get_go_to_falkreath_from_west_forest() const {
  return is_go_to_falkreath_from_west_forest;
}

bool LocationSystem::get_go_to_west_forest_from_falkreath() const {
  return is_go_to_west_forest_from_falkreath;
}

bool LocationSystem::get_story_end() const {
  return is_story_end;
}

EntitiesSystem *LocationSystem::get_entities() {
  return entities;
}

EntitiesSystem *LocationSystem::get_entities() const {
  return entities;
}

unsigned LocationSystem::get_size_x() const {
  return size_x;
}

unsigned LocationSystem::get_size_y() const {
  return size_y;
}

void LocationSystem::set_location(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                                  EntitiesSystem *input_entities_system) {
  name = input_name;
  size_x = input_size_x;
  size_y = input_size_y;
  delete entities;
  entities = new EntitiesSystem(*input_entities_system);
}
