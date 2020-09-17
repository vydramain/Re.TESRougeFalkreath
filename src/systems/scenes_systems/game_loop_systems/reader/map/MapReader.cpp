//
// Created by vydra on 9/4/20.
//

#include "systems/scenes_systems/game_loop_systems/reader/map/MapReader.hpp"

#include <string>

MapReader::MapReader(std::string* input_file_name) {
  file_name = input_file_name;
}

MapReader::~MapReader() {
  if (file != nullptr) {
    fclose(file);
  }
  delete file_name;
}

std::string* MapReader::get_file_name() {
  return file_name;
}

bool MapReader::is_file() {
  if (file != nullptr) {
    if (!feof(file)) {
      return true;
    }
  }
  return false;
}
