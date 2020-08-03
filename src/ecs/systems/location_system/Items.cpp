//
// Created by vydra on 8/3/20.
//

#include "ecs/systems/location_system/Items.h"

Items::Items(const unsigned input_count) {
  vec_items.reserve(input_count);
}

Items::~Items() {
  vec_items.clear();
}

void Items::put_item(Item input_item) {
  vec_items.push_back(input_item);
}

Item *Items::remove_item(unsigned int input_index) {
  Item *pointer = vec_items.data();
  auto *returning_item = new Item(pointer[input_index]);
  vec_items.erase(vec_items.begin() + input_index);
  return returning_item;
}

unsigned Items::get_size() const {
  return vec_items.size();
}

int Items::get_item_index(Item *input_item) {
  auto it = std::find(vec_items.begin(), vec_items.end(), *input_item);
  return std::distance(vec_items.begin(), it);
}

int Items::get_item_index(unsigned int input_x, unsigned int input_y) {
  for (auto &vec_item : vec_items) {
    if (vec_item.get_current_x() == input_x && vec_item.get_current_y() == input_y) {
      auto it = std::find(vec_items.begin(), vec_items.end(), vec_item);
      return std::distance(vec_items.begin(), it);
    }
  }
  return -1;
}
const Item *Items::get_item(const unsigned int input_index) const {
  const Item *pointer = vec_items.data();
  return &pointer[input_index];
}
