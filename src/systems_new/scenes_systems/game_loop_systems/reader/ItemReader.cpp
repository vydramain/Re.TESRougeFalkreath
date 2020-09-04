//
// Created by vydra on 9/4/20.
//

#include "systems_new/scenes_systems/game_loop_systems/reader/ItemReader.hpp"

void ItemReader::clear_item_data() {
  items_count = 0;
  item_type = nullptr;
  items_location.clear();
}

ItemReader::ItemReader(const char* input_file_name) {
  file_name = input_file_name;
}

ItemReader::~ItemReader() {
  if (file != nullptr) {
    fclose(file);
  }
}

const char* ItemReader::get_file_name() {
  return file_name;
}

bool ItemReader::open() {
  file = fopen(file_name, "r");
  if (file != nullptr || feof(file)) {
    return true;
  }
  return false;
}

bool ItemReader::has_item() {
  return feof(file);
}
bool ItemReader::load_item() {
  clear_item_data();
  if (fscanf(file, "%s", item_type) == 0) {
    getc(file);
    if (fscanf(file, "%u", &items_count) == 0) {
      unsigned temp_x, temp_y;
      for (unsigned i = 0; i < items_count; i++) {
        if (fscanf(file, "%u %u", &temp_x, &temp_y) == 0) {
          getc(file);
      items_location.emplace_back(temp_x, temp_y);
        }
      }
      return true;
    }
  }
  clear_item_data();
  return false;
}
std::string ItemReader::get_item_type() {
  return std::string(item_type);
}

unsigned ItemReader::get_items_count() {
  return items_count;
}

unsigned ItemReader::get_item_x(unsigned int input_item_index) {
  return items_location[input_item_index].first;
}

unsigned ItemReader::get_item_y(unsigned int input_item_index) {
  return items_location[input_item_index].second;
}
