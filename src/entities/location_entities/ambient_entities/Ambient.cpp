//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Ambient.h"

Ambient::Ambient(const char *input_name, PseudoRenderData *input_pseudo_data, GraficRenderData *input_grafic_data,
                 unsigned int input_x, unsigned int input_y, bool is_floor)
    : LocationsEntity(input_name, input_pseudo_data, input_grafic_data),
      SubLocatable(input_x, input_y),
      SubFloor(is_floor) {}

Ambient::~Ambient() = default;

bool Ambient::operator==(const Ambient &rhs) const {
  return get_name() == rhs.get_name() && get_pseudo_tile() == rhs.get_pseudo_tile() &&
         get_pseudo_color() == rhs.get_pseudo_color();
}

bool Ambient::operator!=(const Ambient &rhs) const {
  return !(rhs == *this);
}
