//
// Created by vydra on 9/3/20.
//

#include "systems/scenes_systems/game_loop_systems/world/WorldSystem.hpp"

#include <string>
#include <vector>

WorldSystem::WorldSystem() = default;

WorldSystem::~WorldSystem() {
  maps.clear();
  current_map = nullptr;
}

void WorldSystem::add_new_map(std::string* input_map_address) {
  auto* load_system = new SectionalLoadSystem(input_map_address);
  load_system->load_new_map();
  auto* map = load_system->get_map_system();
  maps.push_back(map);
  delete load_system;
}

void WorldSystem::add_rnd_map(std::string* input_map_name) {
  auto* automap = new AutoMapSystem(input_map_name);
  auto* map = automap->generate_location();
  maps.push_back(map);
  delete automap;
}

void WorldSystem::add_old_map(std::string* input_map_address) {
  auto* load_system = new SectionalLoadSystem(input_map_address);
  load_system->load_old_map();
  auto* map = load_system->get_map_system();
  maps.push_back(map);
  delete load_system;
}

void WorldSystem::set_current_map(std::string* input_name) {
  for (IMapSystem* map : maps) {
    if (input_name->data() == map->get_name()) {
      current_map = map;
      return;
    }
  }
  current_map = nullptr;
}

void WorldSystem::set_ending_game(bool input_ending) {
  ending = input_ending;
}

bool WorldSystem::get_ending_game() const {
  return ending;
}

IMapSystem* WorldSystem::get_current_map() {
  return current_map;
}

IMapSystem* WorldSystem::get_current_map() const {
  return current_map;
}

std::vector<std::string>* WorldSystem::get_maps_names() {
  auto* maps_names = new std::vector<std::string>();
  for (auto map : maps) {
    maps_names->push_back(map->get_name());
  }
  return maps_names;
}
