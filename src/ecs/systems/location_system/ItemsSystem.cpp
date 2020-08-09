//
// Created by vydra on 8/3/20.
//

#include "ecs/systems/location_system/sub_systems/entities_system/ItemsSystem.h"

ItemsSystem::ItemsSystem(const unsigned input_count) {
  items.reserve(input_count);
}

ItemsSystem::~ItemsSystem() {
  items.clear();
}

void ItemsSystem::put_item(Item *input_item) {
  items.push_back(input_item);
}

Item *ItemsSystem::remove_item(unsigned int input_index) {
  Item *returning_item = items[input_index];
  items.erase(items.begin() + input_index);
  return returning_item;
}

unsigned ItemsSystem::get_size() const {
  return items.size();
}

int ItemsSystem::get_item_index(Item *input_item) {
  for (unsigned int i = 0; i < items.size(); i++) {
    if (*items[i] == *input_item) {
      return i;
    }
  }
  return -1;
}

int ItemsSystem::get_item_index(unsigned int input_x, unsigned int input_y) {
  for (unsigned int i = 0; i < items.size(); i++) {
    if (items[i]->get_current_x() == input_x && items[i]->get_current_y() == input_y) {
      return i;
    }
  }
  return -1;
}

const Item *ItemsSystem::get_item(unsigned int input_index) const {
  const Item *pointer = items[input_index];
  return pointer;
}
