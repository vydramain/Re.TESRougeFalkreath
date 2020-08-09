//
// Created by vydra on 8/7/20.
//

#include "core/components/sub_components/SubLocatable.hpp"

SubLocatable::SubLocatable(unsigned int input_x, unsigned int input_y) : AbsLocatable(input_x, input_y) {}

SubLocatable::~SubLocatable() = default;

unsigned int SubLocatable::get_current_x() const {
    return current_x;
}

unsigned int SubLocatable::get_current_y() const {
    return current_y;
}

void SubLocatable::set_current_x(unsigned int input_x) {
    current_x = input_x;
}

void SubLocatable::set_current_y(unsigned int input_y) {
    current_y = input_y;
}
