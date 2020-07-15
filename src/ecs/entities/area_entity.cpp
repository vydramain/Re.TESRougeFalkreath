//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/g_area.h"

unsigned g_area::get_size_x() {
    return size_x;
}

unsigned g_area::get_size_y() {
    return size_y;
}

char g_area::get_cell(unsigned input_x, unsigned input_y) {
    return data[input_x][input_y];
}
