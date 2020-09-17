//
// Created by vydra on 8/3/20.
//

#include "entities/location_entities/sentients_entities/Sentient.h"

Sentient::Sentient(SentientParametersData *input_data)
    : SubNickname(input_data->get_nickname().data()),
      LocationsEntity(input_data->get_name().data(), input_data->get_pseudo_data(), input_data->get_grafic_data()),
      SubLiveStats(input_data->get_hp(), input_data->get_mp(), input_data->get_ap()),
      SubWalketh(input_data->get_x(), input_data->get_y()),
      SubPockets(input_data->get_pocket_size()),
      SubSentientCondition() {}

Sentient::Sentient(const Sentient &input_sentient)
    : SubNickname(input_sentient.get_nickname()->data()),
      LocationsEntity(input_sentient.get_name()->data(),
                      new PseudoRenderData(input_sentient.get_pseudo_tile(), input_sentient.get_pseudo_color()),
                      new GraficRenderData(input_sentient.get_grafic_tile())),
      SubLiveStats(input_sentient.get_hp(), input_sentient.get_mp(), input_sentient.get_ap()),
      SubWalketh(input_sentient.get_current_x(), input_sentient.get_current_y()),
      SubPockets(input_sentient.get_pocket_size()),
      SubSentientCondition(input_sentient.get_current_condition()) {
  set_sight();
  set_wallet(input_sentient.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    if (get_item(i) != nullptr) {
      put_item(new Item(*get_item(i)));
    }
  }
}

Sentient::Sentient(Sentient &&input_sentient) noexcept
    : SubNickname(input_sentient.get_nickname()->data()),
      LocationsEntity(input_sentient.get_name()->data(),
                      new PseudoRenderData(input_sentient.get_pseudo_tile(), input_sentient.get_pseudo_color()),
                      new GraficRenderData(input_sentient.get_grafic_tile())),
      SubLiveStats(input_sentient.get_hp(), input_sentient.get_mp(), input_sentient.get_ap()),
      SubWalketh(input_sentient.get_current_x(), input_sentient.get_current_y()),
      SubPockets(input_sentient.get_pocket_size()),
      SubSentientCondition(input_sentient.get_current_condition()) {
  set_sight();
  set_wallet(input_sentient.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(remove_item(i));
  }
}

Sentient::~Sentient() = default;

Sentient &Sentient::operator=(const Sentient &input_race) {
  set_name(input_race.get_name()->data());
  set_pseudo_tile(input_race.get_pseudo_tile());
  set_pseudo_color(input_race.get_pseudo_color());
  set_grafic_tile(input_race.get_grafic_tile());
  set_hp(input_race.get_hp());
  set_mp(input_race.get_mp());
  set_ap(input_race.get_ap());
  set_status(input_race.get_status());
  set_nickname(input_race.get_nickname());
  current_x = input_race.get_current_x();
  current_y = input_race.get_current_y();
  set_sight();
  set_wallet(input_race.get_wallet());
  set_current_condition(input_race.get_current_condition());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(new Item(*get_item(i)));
  }
  return *this;
}
Sentient &Sentient::operator=(Sentient &&input_race) noexcept {
  set_name(input_race.get_name()->data());
  set_pseudo_tile(input_race.get_pseudo_tile());
  set_pseudo_color(input_race.get_pseudo_color());
  set_grafic_tile(input_race.get_grafic_tile());
  set_hp(input_race.get_hp());
  set_mp(input_race.get_mp());
  set_ap(input_race.get_ap());
  set_status(input_race.get_status());
  set_nickname(input_race.get_nickname());
  current_x = input_race.get_current_x();
  current_y = input_race.get_current_y();
  set_sight();
  set_wallet(input_race.get_wallet());
  set_current_condition(input_race.get_current_condition());
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
