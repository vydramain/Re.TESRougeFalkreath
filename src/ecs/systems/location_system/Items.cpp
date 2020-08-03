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

void Items::put_item(Item *input_item) {
  vec_items.push_back(*input_item);
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
  if (it != vec_items.end()) {
    return std::distance(vec_items.begin(), it);
  }
  return -1;
}

int Items::get_item_index(unsigned int input_x, unsigned int input_y) {
  for (auto it = vec_items.begin(); it < vec_items.end(); it++) {
    if (it->get_current_x() == input_x && it->get_current_y() == input_y) {
      return std::distance(vec_items.begin(), it);
    }
  }
  return -1;
}

const Item *Items::get_item(unsigned int input_index) const {
  const Item *pointer = vec_items.data();
  return &pointer[input_index];
}
