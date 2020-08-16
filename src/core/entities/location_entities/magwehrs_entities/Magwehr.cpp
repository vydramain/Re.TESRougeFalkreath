//
// Created by vydra on 15.07.2020.
//

#include "core/entities/location_enities/magwehrs_entities/Magwehr.h"

Magwehr::Magwehr(const char *input_name, const char *input_tile, unsigned input_color, const unsigned input_x,
                 const unsigned input_y)
    : LocationsEntity(input_name, input_tile, input_color), SubWalketh(input_x, input_y) {
  set_sight();
}

Magwehr::Magwehr(const Magwehr &input_magwehr)
    : LocationsEntity(input_magwehr.get_name(), input_magwehr.get_tile(), input_magwehr.get_color()),
      SubWalketh(input_magwehr.get_current_x(), input_magwehr.get_current_y()) {
  set_sight();
}

Magwehr::Magwehr(Magwehr &&input_magwehr) noexcept
    : LocationsEntity(input_magwehr.get_name(), input_magwehr.get_tile(), input_magwehr.get_color()),
      SubWalketh(input_magwehr.get_current_x(), input_magwehr.get_current_y()) {
  set_sight();
}

Magwehr &Magwehr::operator=(const Magwehr &input_magwehr) {
  set_name(input_magwehr.get_name());
  set_tile(input_magwehr.get_tile());
  set_color(input_magwehr.get_color());
  current_x = input_magwehr.get_current_x();
  current_y = input_magwehr.get_current_y();
  set_sight();
  return *this;
}

Magwehr &Magwehr::operator=(Magwehr &&input_magwehr) noexcept {
  set_name(input_magwehr.get_name());
  set_tile(input_magwehr.get_tile());
  set_color(input_magwehr.get_color());
  current_x = input_magwehr.get_current_x();
  current_y = input_magwehr.get_current_y();
  set_sight();
  return *this;
}

Magwehr::~Magwehr() = default;

bool Magwehr::operator==(const Magwehr &rhs) const {
  return get_name() == rhs.get_name() && get_tile() == rhs.get_tile() && get_color() == rhs.get_color();
}
bool Magwehr::operator!=(const Magwehr &rhs) const {
  return !(rhs == *this);
}
