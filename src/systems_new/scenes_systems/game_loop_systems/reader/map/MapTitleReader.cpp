//
// Created by vydra on 9/3/20.
//

#include "systems_new/scenes_systems/game_loop_systems/reader/map/MapTitleReader.hpp"

#include <utility>

MapTitleReader::MapTitleReader(std::string input_file_name) : MapReader(std::move(input_file_name)) {}

MapTitleReader::~MapTitleReader() = default;

bool MapTitleReader::open() {
  if (file == nullptr) {
    file = fopen(file_name.data(), "r");
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

std::string MapTitleReader::get_map_name() {
  return std::string(map_name);
}

unsigned int MapTitleReader::get_map_size_x() const {
  return size_x;
}

unsigned int MapTitleReader::get_map_size_y() const {
  return size_y;
}
