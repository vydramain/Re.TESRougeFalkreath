//
// Created by vydra on 9/2/20.
//

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/MapSystem.hpp"

#include <utility>

MapSystem::MapSystem(std::string input_name, unsigned int input_size_x, unsigned int input_size_y,
                     EntitiesSystem *input_entities_system) {
  name = std::move(input_name);
  size_x = input_size_x;
  size_y = input_size_y;
  entities_system = new EntitiesSystem(*input_entities_system);
}

MapSystem::~MapSystem() {
  delete entities_system;
}

std::string MapSystem::get_name() {
  return name;
}

unsigned MapSystem::get_size_x() {
  return size_x;
}

unsigned MapSystem::get_size_y() {
  return size_y;
}

EntitiesSystem* MapSystem::get_entities_system() {
  return entities_system;
}
