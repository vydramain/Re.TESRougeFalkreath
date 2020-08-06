//
// Created by vydra on 8/3/20.
//

#include "ecs/entities/items_entities/Item.h"

Item::Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y)
    : SubPickable(input_pick, input_x, input_y), name(input_name) {}

Item::~Item() = default;

bool Item::operator==(const Item& rhs) const {
  return name == rhs.name;
}

bool Item::operator!=(const Item& rhs) const {
  return !(rhs == *this);
}

const char* Item::get_name() const {
  return name;
}

void Item::set_name(const char* input_name) {
  name = input_name;
}
