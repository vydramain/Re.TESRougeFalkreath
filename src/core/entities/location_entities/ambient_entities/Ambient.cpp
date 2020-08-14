//
// Created by vydra on 8/14/20.
//

#include "core/entities/location_enities/ambient_entities/Ambient.h"

Ambient::Ambient(const char *input_name, char input_tile, unsigned int input_color, unsigned int input_x,
                 unsigned int input_y)
    : LocationsEntity(input_name, input_tile, input_color), SubLocatable(input_x, input_y) {}

Ambient::~Ambient() = default;

bool Ambient::operator==(const Ambient &rhs) const {
  return get_name() == rhs.get_name() && get_tile() == rhs.get_tile() && get_color() == rhs.get_color();
}

bool Ambient::operator!=(const Ambient &rhs) const {
  return !(rhs == *this);
}
