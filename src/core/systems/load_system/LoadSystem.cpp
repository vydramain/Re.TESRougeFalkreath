//
// Created by vydra on 8/14/20.
//

#include "core/systems/load_system/LoadSystem.h"

LoadSystem::LoadSystem() {
  location_size_x = 0;
  location_size_y = 0;
  entities_system = nullptr;
  map_file_stream = nullptr;
}

LoadSystem::~LoadSystem() {
  if (map_file_stream != nullptr) {
    fclose(map_file_stream);
  }
  if (entities_system != nullptr) {
    delete entities_system;
  }
}

bool LoadSystem::check_file() {
  return feof(map_file_stream);
}

void LoadSystem::clear_fields() {
  location_size_x = 0;
  location_size_y = 0;
  if (!entities_system) {
    delete entities_system;
  }
}

void LoadSystem::create_entities_system() {
  auto *i = new unsigned(0);
  auto *j = new unsigned(0);
  entities_system = new LocationsEntitiesSystem();
  IControl *control;
  auto *map = new LControlMap(i, j, entities_system);

  if (map_file_stream != nullptr) {
    fscanf(map_file_stream, "%u", &location_size_x);
    if (check_file()) {
      clear_fields();
      delete entities_system;
      entities_system = nullptr;
      delete map;
      return;
    }

    fscanf(map_file_stream, "%u", &location_size_y);
    if (check_file()) {
      clear_fields();
      delete entities_system;
      entities_system = nullptr;
      delete map;
      return;
    }

    getc(map_file_stream);
    for (*j = 0; *j < location_size_y; *j = *j + 1) {
      for (*i = 0; *i < location_size_x; *i = *i + 1) {
        control = map->get_control(getc(map_file_stream));
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
}

void LoadSystem::load_map(const char *input_map_name) {
  delete entities_system;

  map_file_stream = fopen(input_map_name, "r");
  if (map_file_stream == nullptr) {
    return;
  }

  fseek(map_file_stream, 0, SEEK_SET);
  if (feof(map_file_stream)) {
    fclose(map_file_stream);
    map_file_stream = nullptr;
  }
  create_entities_system();
}

LocationsEntitiesSystem *LoadSystem::get_entities_system() const {
  return entities_system;
}

unsigned LoadSystem::get_location_size_x() const {
  return location_size_x;
}

unsigned int LoadSystem::get_location_size_y() const {
  return location_size_y;
}
