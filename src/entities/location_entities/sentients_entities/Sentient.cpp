//
// Created by vydra on 8/3/20.
//

#include "entities/location_entities/sentients_entities/Sentient.h"

Sentient::Sentient(const char *input_fio, const char *input_name, PseudoRenderData *input_pseudo_data,
                   GraficRenderData *input_grafic_data, const unsigned input_current_x, const unsigned input_current_y,
                   const unsigned input_pocket_size, const unsigned input_wallet)
    : SubNickname(input_fio),
      LocationsEntity(input_name, input_pseudo_data, input_grafic_data),
      SubWalketh(input_current_x, input_current_y),
      SubPockets(input_pocket_size) {}

Sentient::Sentient(const Sentient &input_sentient)
    : SubNickname(input_sentient.get_fio()),
      LocationsEntity(input_sentient.get_name(),
                      new PseudoRenderData(input_sentient.get_pseudo_tile(), input_sentient.get_pseudo_color()),
                      new GraficRenderData(input_sentient.get_grafic_tile())),
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
    : SubNickname(input_sentient.get_fio()),
      LocationsEntity(input_sentient.get_name(),
                      new PseudoRenderData(input_sentient.get_pseudo_tile(), input_sentient.get_pseudo_color()),
                      new GraficRenderData(input_sentient.get_grafic_tile())),
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
  set_pseudo_tile(input_race.get_pseudo_tile());
  set_pseudo_color(input_race.get_pseudo_color());
  set_grafic_tile(input_race.get_grafic_tile());
  set_fio(input_race.get_fio());
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
  set_pseudo_tile(input_race.get_pseudo_tile());
  set_pseudo_color(input_race.get_pseudo_color());
  set_grafic_tile(input_race.get_grafic_tile());
  set_fio(input_race.get_fio());
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
  return get_name() == rhs.get_name() && get_pseudo_tile() == rhs.get_pseudo_tile() &&
         get_pseudo_color() == rhs.get_pseudo_color();
}

bool Sentient::operator!=(const Sentient &rhs) const {
  return !(rhs == *this);
}
