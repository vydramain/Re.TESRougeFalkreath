//
// Created by vydra on 8/7/20.
//

#include "ecs/components/sub_components/SubPickable.hpp"

SubPickable::SubPickable(bool input_pick, unsigned input_x, unsigned input_y)
        : AbsPickable(input_pick), SubLocatable(input_x, input_y) {}

SubPickable::~SubPickable() = default;

void SubPickable::ejected(unsigned int input_x, unsigned int input_y) {
    is_picked_up = false;
    set_current_x(input_x);
    set_current_y(input_y);
}
void SubPickable::picked_up() {
    is_picked_up = true;
}
bool SubPickable::has_pick_up() const {
    return is_picked_up;
}
