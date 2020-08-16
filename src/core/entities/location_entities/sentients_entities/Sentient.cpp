//
// Created by vydra on 8/3/20.
//

#include "core/entities/location_enities/sentients_entities/Sentient.h"

Sentient::Sentient(const char *input_name, const char* input_tile, unsigned input_color, const unsigned input_current_x,
                   const unsigned input_current_y, const unsigned input_pocket_size, const unsigned input_wallet)
    : LocationsEntity(input_name, input_tile, input_color),
      SubWalketh(input_current_x, input_current_y),
      SubPockets(input_pocket_size) {}

Sentient::Sentient(const Sentient &input_sentient)
    : LocationsEntity(input_sentient.get_name(), input_sentient.get_tile(), input_sentient.get_color()),
      SubWalketh(input_sentient.get_current_x(), input_sentient.get_current_y()),
      SubPockets(input_sentient.get_pocket_size()) {
  set_sight();
  set_wallet(input_sentient.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    if (get_item(i) != nullptr) {
      put_item(new Item(*get_item(i)));
    }
  }
}

Sentient::Sentient(Sentient &&input_sentient) noexcept
    : LocationsEntity(input_sentient.get_name(), input_sentient.get_tile(), input_sentient.get_color()),
      SubWalketh(input_sentient.get_current_x(), input_sentient.get_current_y()),
      SubPockets(input_sentient.get_pocket_size()) {
  set_sight();
  set_wallet(input_sentient.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(remove_item(i));
  }
}

Sentient::~Sentient() = default;

Sentient &Sentient::operator=(const Sentient &input_race) {
  set_name(input_race.get_name());
  set_tile(input_race.get_tile());
  set_color(input_race.get_color());
  current_x = input_race.get_current_x();
  current_y = input_race.get_current_y();
  set_sight();
  set_wallet(input_race.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(new Item(*get_item(i)));
  }
  return *this;
}
Sentient &Sentient::operator=(Sentient &&input_race) noexcept {
  set_name(input_race.get_name());
  set_tile(input_race.get_tile());
  set_color(input_race.get_color());
  current_x = input_race.get_current_x();
  current_y = input_race.get_current_y();
  set_sight();
  set_wallet(input_race.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(remove_item(i));
  }
  return *this;
}

bool Sentient::operator==(const Sentient &rhs) const {
  return get_name() == rhs.get_name() && get_tile() == rhs.get_tile() && get_color() == rhs.get_color();
}

bool Sentient::operator!=(const Sentient &rhs) const {
  return !(rhs == *this);
}
