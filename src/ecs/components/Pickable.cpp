//
// Created by vydra on 8/3/20.
//

#include "ecs/components/Pickable.h"

Pickable::Pickable(bool input_pick, unsigned input_x, unsigned input_y)
    : Locateable(input_x, input_y), picked_up(input_pick) {}

Pickable::~Pickable() = default;

void Pickable::ejected(unsigned int input_x, unsigned int input_y) {
  picked_up = false;
  set_current_x(input_x);
  set_current_y(input_y);
}
void Pickable::pick_up() {
  picked_up = true;
}
bool Pickable::has_pick_up() const {
  return picked_up;
}
