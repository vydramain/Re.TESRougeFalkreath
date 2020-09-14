//
// Created by vydra on 9/4/20.
//

#include "systems/scenes_systems/game_loop_systems/reader/map/MapItemReader.hpp"

#include <string>

void MapItemReader::clear_item_data() {
  items_count = 0;
  item_type.clear();
  items_location.clear();
}

MapItemReader::MapItemReader(std::string input_file_name) : MapReader(std::move(input_file_name)) {}

MapItemReader::~MapItemReader() = default;

bool MapItemReader::open() {
  file = fopen(file_name.data(), "r");
  if (file != nullptr) {
    if (!feof(file)) {
      return true;
    }
  }
  return false;
}

bool MapItemReader::has_item() {
  return !feof(file);
}
bool MapItemReader::load_item() {
  clear_item_data();
  char temp_character = getc(file);
  while (temp_character != ' ' && !feof(file)) {
    item_type.append(sizeof(char), temp_character);
    temp_character = getc(file);
  }
  if (fscanf(file, "%u", &items_count) != 0) {
    getc(file);
    unsigned temp_x, temp_y;
    for (unsigned i = 0; i < items_count; i++) {
      if (fscanf(file, "%u %u", &temp_x, &temp_y) != 0) {
        getc(file);
        items_location.emplace_back(temp_x, temp_y);
      }
    }
    return true;
  }
  clear_item_data();
  return false;
}

std::string MapItemReader::get_item_type() {
  return item_type;
}

unsigned MapItemReader::get_items_count() {
  return items_count;
}

unsigned MapItemReader::get_item_x(unsigned int input_item_index) {
  return items_location[input_item_index].first;
}

unsigned MapItemReader::get_item_y(unsigned int input_item_index) {
  return items_location[input_item_index].second;
}
