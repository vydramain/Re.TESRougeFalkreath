//
// Created by vydra on 8/3/20.
//

#include "ecs/entities/location_enities/races_entities/Race.h"

Race::Race(const char *input_name, const unsigned input_current_x, const unsigned input_current_y,
           const unsigned input_pocket_size, const unsigned input_wallet)
    : SubWalketh(input_current_x, input_current_y), SubPockets(input_pocket_size), name(input_name) {}

Race::Race(const Race &input_race)
    : SubWalketh(input_race.get_current_x(), input_race.get_current_y()),
      SubPockets(input_race.get_pocket_size()),
      name(input_race.get_name()) {
  set_sight();
  set_wallet(input_race.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    if (get_item(i) != nullptr) {
      put_item(new Item(*get_item(i)));
    }
  }
}

Race::Race(Race &&input_race) noexcept
    : SubWalketh(input_race.get_current_x(), input_race.get_current_y()),
      SubPockets(input_race.get_pocket_size()),
      name(input_race.get_name()) {
  set_sight();
  set_wallet(input_race.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(remove_item(i));
  }
}

Race &Race::operator=(const Race &input_race) {
  name = input_race.get_name();
  current_x = input_race.get_current_x();
  current_y = input_race.get_current_y();
  set_sight();
  set_wallet(input_race.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(new Item(*get_item(i)));
  }
  return *this;
}
Race &Race::operator=(Race &&input_race) noexcept {
  name = input_race.get_name();
  current_x = input_race.get_current_x();
  current_y = input_race.get_current_y();
  set_sight();
  set_wallet(input_race.get_wallet());
  for (unsigned i = 0; i < get_pocket_size(); i++) {
    put_item(remove_item(i));
  }
  return *this;
}
const char *Race::get_name() const {
  return name;
}
void Race::set_name(const char *input_name) {
  name = input_name;
}
