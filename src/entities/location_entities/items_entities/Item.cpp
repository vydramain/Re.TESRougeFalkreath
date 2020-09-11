//
// Created by vydra on 8/3/20.
//

#include "entities/location_entities/items_entities/Item.h"

Item::Item(const char* input_name, PseudoRenderData* input_pseudo_data, GraficRenderData* input_grafic_data,
           unsigned input_x, unsigned input_y)
    : LocationsEntity(input_name, input_pseudo_data, input_grafic_data), SubPickable(false, input_x, input_y) {}

Item::~Item() = default;

bool Item::operator==(const Item& rhs) const {
  return get_name() == rhs.get_name() && get_pseudo_tile() == rhs.get_pseudo_tile() &&
         get_pseudo_color() == rhs.get_pseudo_color();
}

bool Item::operator!=(const Item& rhs) const {
  return !(rhs == *this);
}
