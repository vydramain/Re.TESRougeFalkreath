//
// Created by vydra on 15.07.2020.
//

#include "core/entities/location_enities/magwehrs_entities/Magwehr.h"

Magwehr::Magwehr(const char *input_name, const unsigned input_x, const unsigned input_y)
    : LocationsEntity(input_name), SubWalketh(input_x, input_y) {
  set_sight();
}

Magwehr::Magwehr(const Magwehr &input_magwehr)
    : LocationsEntity(input_magwehr.get_name()),
      SubWalketh(input_magwehr.get_current_x(), input_magwehr.get_current_y()) {
  set_sight();
}

Magwehr::Magwehr(Magwehr &&input_magwehr) noexcept
    : LocationsEntity(input_magwehr.get_name()),
      SubWalketh(input_magwehr.get_current_x(), input_magwehr.get_current_y()) {
  set_sight();
}

Magwehr &Magwehr::operator=(const Magwehr &input_magwehr) {
  set_name(input_magwehr.get_name());
  current_x = input_magwehr.get_current_x();
  current_y = input_magwehr.get_current_y();
  set_sight();
  return *this;
}

Magwehr &Magwehr::operator=(Magwehr &&input_magwehr) noexcept {
  set_name(input_magwehr.get_name());
  current_x = input_magwehr.get_current_x();
  current_y = input_magwehr.get_current_y();
  set_sight();
  return *this;
}
