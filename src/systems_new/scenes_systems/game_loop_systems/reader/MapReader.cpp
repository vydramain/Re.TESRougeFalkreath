//
// Created by vydra on 9/3/20.
//

#include "systems_new/scenes_systems/game_loop_systems/reader/MapReader.hpp"

MapReader::MapReader(const char* input_file_name) {
  file_name = input_file_name;
}

MapReader::~MapReader() {
  if (file != nullptr) {
    fclose(file);
  }
}

const char* MapReader::get_file_name() {
  return file_name;
}

bool MapReader::open() {
  if (file == nullptr) {
    file = fopen(file_name, "r");
    if (file != nullptr || feof(file)) {
      if (fscanf(file, "%s", map_name)) {
        getc(file);
        if (fscanf(file, "%u %u", &size_x, &size_y) == 0) {
          size_x = 0;
          size_y = 0;
          file = nullptr;
          return false;
        }
      }
      getc(file);
      return true;
    }
  }

  return false;
}

std::string MapReader::get_map_name() {
  return std::string(map_name);
}

unsigned int MapReader::get_map_size_x() {
  return size_x;
}

unsigned int MapReader::get_map_size_y() {
  return size_y;
}
