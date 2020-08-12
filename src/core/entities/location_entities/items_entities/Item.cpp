//
// Created by vydra on 8/3/20.
//

#include "core/entities/location_enities/items_entities/Item.h"

Item::Item(const char* input_name, bool input_pick, const char input_tile, unsigned input_color,
           unsigned input_x, unsigned input_y)
    : LocationsEntity(input_name, input_tile, input_color), SubPickable(input_pick, input_x, input_y) {}

Item::~Item() = default;

bool Item::operator==(const Item& rhs) const {
  return get_name() == rhs.get_name();
}

bool Item::operator!=(const Item& rhs) const {
  return !(rhs == *this);
}
