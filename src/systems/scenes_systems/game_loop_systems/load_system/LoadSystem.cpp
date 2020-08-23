//
// Created by vydra on 8/14/20.
//

#include "systems/scenes_systems/game_loop_systems/load_systems/LoadSystem.h"

LoadSystem::LoadSystem(const char *input_map_name) {
  reader = new StdLocationReader(input_map_name);
  entities_system = nullptr;
}

LoadSystem::~LoadSystem() {
  delete reader;
  delete entities_system;
}

bool LoadSystem::check_file() {
  return reader->has_next();
}

void LoadSystem::clear_fields() {
  delete reader;
  delete entities_system;
}

void LoadSystem::create_entities_system() {
  PseudoLogSystem::log("LoadSystem", "Creating and completion location_systems entities system");

  auto *i = new unsigned(0);
  auto *j = new unsigned(0);
  entities_system = new LocationsEntitiesSystem();
  IControl *control;
  auto *map = new LControlMap(i, j, entities_system);


    for (*j = 0; *j < reader->get_y_location_size(); *j = *j + 1) {
      for (*i = 0; *i < reader->get_x_location_size(); *i = *i + 1) {
        control = map->get_control(reader->get_char());
        control->execute();
        if (check_file()) {
          clear_fields();
          delete entities_system;
          entities_system = nullptr;
          delete i;
          delete j;
          delete map;
          return;
        }
      }
    }

  delete i;
  delete j;
  delete map;
}

void LoadSystem::load_map() {
  if (reader != nullptr) {
    PseudoLogSystem::log("LoadSystem", "Load map", reader->get_file_name());
    delete entities_system;

    if (!reader->open()) {
      PseudoLogSystem::log("LoadSystem", "Map not found");
    }
    create_entities_system();
    return;
  }
  PseudoLogSystem::log("LoadSystem", "Reader not setting up");
}

LocationsEntitiesSystem *LoadSystem::get_entities_system() const {
  return entities_system;
}

unsigned LoadSystem::get_location_size_x() const {
  if (reader == nullptr) {
    return 0;
  }
  return reader->get_x_location_size();
}

unsigned int LoadSystem::get_location_size_y() const {
  if (reader == nullptr) {
    return 0;
  }
  return reader->get_y_location_size();
}
