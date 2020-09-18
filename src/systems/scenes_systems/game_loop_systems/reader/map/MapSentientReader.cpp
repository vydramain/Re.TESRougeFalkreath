//
// Created by vydra on 9/17/20.
//

#include "systems/scenes_systems/game_loop_systems/reader/map/MapSentientReader.hpp"

#include <string>

void MapSentientReader::clear_sentient_data() {
  sentient_name.clear();
  sentient_nickname.clear();
  sentient_x = 0;
  sentient_y = 0;
}

MapSentientReader::MapSentientReader(std::string* input_file_name) : MapReader(input_file_name) {}

MapSentientReader::~MapSentientReader() = default;

bool MapSentientReader::open() {
  file = fopen(file_name->data(), "r");
  if (file != nullptr) {
    if (!feof(file)) {
      return true;
    }
  }
  return false;
}

bool MapSentientReader::has_sentient() {
  return !feof(file);
}

bool MapSentientReader::load_sentient() {
  clear_sentient_data();
  char temp_character = getc(file);
  while (temp_character != '\n' && !feof(file)) {
    sentient_name.append(sizeof(char), temp_character);
    temp_character = getc(file);
  }
  temp_character = getc(file);
  while (temp_character != '\n' && !feof(file)) {
    sentient_nickname.append(sizeof(char), temp_character);
    temp_character = getc(file);
  }
  if (fscanf(file, "%u %u", &sentient_x, &sentient_y) == 0) {
    clear_sentient_data();
    return false;
  }
  getc(file);
  return true;
}

std::string MapSentientReader::get_sentient_name() {
  return sentient_name;
}

std::string MapSentientReader::get_sentient_nickname() {
  return sentient_nickname;
}

unsigned MapSentientReader::get_sentient_x() const {
  return sentient_x;
}

unsigned MapSentientReader::get_sentient_y() const {
  return sentient_y;
}
