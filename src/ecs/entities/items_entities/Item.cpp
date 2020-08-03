//
// Created by vydra on 8/3/20.
//

#include "ecs/entities/items_entities/Item.h"

Item::Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y)
    : Pickable(input_pick, input_x, input_y), name(input_name) {}

Item::Item(const Item& input_creature)
    : Pickable(input_creature.has_pick_up(), input_creature.get_current_x(), input_creature.get_current_y()),
      name(input_creature.get_name()) {}

Item::~Item() = default;

void Item::set_name(const char* input_name) {
  name = input_name;
}

const char* Item::get_name() const {
  return name;
}
bool Item::operator==(const Item& rhs) const {
  return name == rhs.name;
}
bool Item::operator!=(const Item& rhs) const {
  return !(rhs == *this);
}
