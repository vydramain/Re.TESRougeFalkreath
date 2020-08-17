//
// Created by vydra on 8/3/20.
//

#include "entities/location_entities/items_entities/Item.h"

Item::Item(const char* input_name, const char* input_tile, unsigned input_color, unsigned input_x, unsigned input_y)
    : LocationsEntity(input_name, input_tile, input_color), SubPickable(false, input_x, input_y) {}

Item::~Item() = default;

bool Item::operator==(const Item& rhs) const {
  return get_name() == rhs.get_name() && get_tile() == rhs.get_tile() && get_color() == rhs.get_color();
}

bool Item::operator!=(const Item& rhs) const {
  return !(rhs == *this);
}
