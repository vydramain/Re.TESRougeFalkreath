//
// Created by vydra on 9/3/20.
//

#include "systems/scenes_systems/game_loop_systems/reader/map/MapTitleReader.hpp"

#include <string>

MapTitleReader::MapTitleReader(std::string input_file_name) : MapReader(std::move(input_file_name)) {}

MapTitleReader::~MapTitleReader() = default;

bool MapTitleReader::open() {
  if (file == nullptr) {
    file = fopen(file_name.data(), "r");
    if (file != nullptr) {
      if (!feof(file)) {
        map_name.clear();
        char temp_character = getc(file);
        while (temp_character != '\n' && !feof(file)) {
          map_name.append(sizeof(char), temp_character);
          temp_character = getc(file);
        }
        if (fscanf(file, "%u %u", &size_x, &size_y) != 0) {
          return true;
        }
      }
    }
  }
  map_name = nullptr;
  size_x = 0;
  size_y = 0;
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
