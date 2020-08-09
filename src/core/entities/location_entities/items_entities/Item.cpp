//
// Created by vydra on 8/3/20.
//

#include "core/entities/location_enities/items_entities/Item.h"

Item::Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y)
    :  LocationEntity(input_name), SubPickable(input_pick, input_x, input_y) {}

Item::~Item() = default;

bool Item::operator==(const Item& rhs) const {
  return get_name() == rhs.get_name();
}

bool Item::operator!=(const Item& rhs) const {
  return !(rhs == *this);
}
