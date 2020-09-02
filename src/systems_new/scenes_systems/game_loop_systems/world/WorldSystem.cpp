//
// Created by vydra on 9/3/20.
//

#include "systems_new/scenes_systems/game_loop_systems/world/WorldSystem.hpp"

WorldSystem::WorldSystem() = default;

WorldSystem::~WorldSystem() {
  maps.clear();
  current_map = nullptr;
}

void WorldSystem::add_world(IMapSystem *input_map_system) {
  maps.push_back(input_map_system);
}

void WorldSystem::set_current_map(std::string input_name) {
  for(IMapSystem *map : maps) {
    if (input_name == map->get_name()){
      current_map = map;
      return;
    }
  }
}

IMapSystem* WorldSystem::get_current_map() {
  return current_map;
}

IMapSystem* WorldSystem::get_current_map() const {
  return current_map;
}
