//
// Created by vydra on 9/3/20.
//

#include "systems/scenes_systems/game_loop_systems/reader/map/MapAmbientReader.hpp"

#include <string>

MapAmbientReader::MapAmbientReader(std::string input_file_name) : MapReader(std::move(input_file_name)) {}

MapAmbientReader::~MapAmbientReader() = default;

bool MapAmbientReader::open() {
  file = fopen(file_name.data(), "r");
  if (file != nullptr) {
    if (!feof(file)) {
      return true;
    }
  }
  return false;
}

bool MapAmbientReader::has_next() {
  return feof(file);
}

unsigned int MapAmbientReader::get_char() {
  return getc(file);
}
