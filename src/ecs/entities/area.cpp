//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/area.h"

const unsigned area::get_size_x() {
    return size_x;
}

const unsigned area::get_size_y() {
    return size_y;
}

const char area::get_cell(unsigned input_x, unsigned input_y) {
    return data[input_x][input_y];
}
