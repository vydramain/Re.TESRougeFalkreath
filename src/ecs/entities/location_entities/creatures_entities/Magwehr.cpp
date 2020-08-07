//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/location_enities/creatures_entities/Magwehr.h"

Magwehr::Magwehr(const char *input_name, const unsigned input_x, const unsigned input_y)
    : SubWalketh(input_x, input_y), name(input_name) {
  set_sight();
}

Magwehr::Magwehr(const Magwehr &input_creature)
    : SubWalketh(input_creature.get_current_x(), input_creature.get_current_y()), name(input_creature.name) {
  set_sight();
}

Magwehr::Magwehr(Magwehr &&input_creature) noexcept
    : SubWalketh(input_creature.get_current_x(), input_creature.get_current_y()), name(input_creature.name) {
  set_sight();
}

Magwehr &Magwehr::operator=(const Magwehr &input_creature) {
  name = input_creature.get_name();
  current_x = input_creature.get_current_x();
  current_y = input_creature.get_current_y();
  set_sight();
  return *this;
}

Magwehr &Magwehr::operator=(Magwehr &&input_creature) noexcept {
  name = input_creature.get_name();
  current_x = input_creature.get_current_x();
  current_y = input_creature.get_current_y();
  set_sight();
  return *this;
}

const char *Magwehr::get_name() const {
  return name;
}

void Magwehr::set_name(const char *input_name) {
  name = input_name;
}
