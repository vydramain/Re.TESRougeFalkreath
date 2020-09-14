//
// Created by vydra on 15.07.2020.
//

#include "entities/location_entities/magwehrs_entities/Magwehr.h"

Magwehr::Magwehr(const char *input_name, PseudoRenderData *input_pseudo_data, GraficRenderData *input_grafic_data,
                 const unsigned input_x, const unsigned input_y)
    : LocationsEntity(input_name, input_pseudo_data, input_grafic_data), SubWalketh(input_x, input_y) {
  set_sight();
}

Magwehr::Magwehr(const Magwehr &input_magwehr)
    : LocationsEntity(input_magwehr.get_name(),
                      new PseudoRenderData(input_magwehr.get_pseudo_tile(), input_magwehr.get_pseudo_color()),
                      new GraficRenderData(input_magwehr.get_grafic_tile())),
      SubWalketh(input_magwehr.get_current_x(), input_magwehr.get_current_y()) {
  set_sight();
}

Magwehr::Magwehr(Magwehr &&input_magwehr) noexcept
    : LocationsEntity(input_magwehr.get_name(),
                      new PseudoRenderData(input_magwehr.get_pseudo_tile(), input_magwehr.get_pseudo_color()),
                      new GraficRenderData(input_magwehr.get_grafic_tile())),
      SubWalketh(input_magwehr.get_current_x(), input_magwehr.get_current_y()) {
  set_sight();
}

Magwehr &Magwehr::operator=(const Magwehr &input_magwehr) {
  set_name(input_magwehr.get_name());
  set_pseudo_tile(input_magwehr.get_pseudo_tile());
  set_pseudo_color(input_magwehr.get_pseudo_color());
  set_grafic_tile(input_magwehr.get_grafic_tile());
  current_x = input_magwehr.get_current_x();
  current_y = input_magwehr.get_current_y();
  set_sight();
  return *this;
}

Magwehr &Magwehr::operator=(Magwehr &&input_magwehr) noexcept {
  set_name(input_magwehr.get_name());
  set_pseudo_tile(input_magwehr.get_pseudo_tile());
  set_pseudo_color(input_magwehr.get_pseudo_color());
  set_grafic_tile(input_magwehr.get_grafic_tile());
  current_x = input_magwehr.get_current_x();
  current_y = input_magwehr.get_current_y();
  set_sight();
  return *this;
}

Magwehr::~Magwehr() = default;

bool Magwehr::operator==(const Magwehr &rhs) const {
  return get_name() == rhs.get_name() && get_pseudo_tile() == rhs.get_pseudo_tile() &&
         get_pseudo_color() == rhs.get_pseudo_color();
}
bool Magwehr::operator!=(const Magwehr &rhs) const {
  return !(rhs == *this);
}
