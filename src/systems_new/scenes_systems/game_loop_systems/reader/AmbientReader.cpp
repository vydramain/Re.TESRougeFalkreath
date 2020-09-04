//
// Created by vydra on 9/3/20.
//

#include "systems_new/scenes_systems/game_loop_systems/reader/AmbientReader.hpp"

AmbientReader::AmbientReader(const char *input_file_name) {
  file_name = input_file_name;
}

AmbientReader::~AmbientReader() {
  if(file != nullptr) {
    fclose(file);
  }
}

const char* AmbientReader::get_file_name() {
  return file_name;
}

bool AmbientReader::open() {
  file = fopen(file_name, "r");
  if (file != nullptr || feof(file)) {
    return true;
  }
  return false;
}

bool AmbientReader::has_next() {
  return feof(file);
}

unsigned int AmbientReader::get_char() {
  return getc(file);
}
