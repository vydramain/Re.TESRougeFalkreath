//
// Created by vydra on 9/4/20.
//

#include "systems/scenes_systems/game_loop_systems/reader/map/MapReader.hpp"

MapReader::MapReader(std::string input_file_name) {
  file_name = std::move(input_file_name);
}

MapReader::~MapReader() {
  if (file != nullptr) {
    fclose(file);
  }
}

std::string MapReader::get_file_name() {
  return file_name;
}

bool MapReader::is_file() {
  if(file != nullptr) {
    if(!feof(file)){
      return true;
    }
  }
  return false;
}
