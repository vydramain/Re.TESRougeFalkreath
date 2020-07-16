//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/area_entity.h"

unsigned area_entity::get_size_x() {
    return size_x;
}

unsigned area_entity::get_size_y() {
    return size_y;
}

char area_entity::get_cell(unsigned input_x, unsigned input_y) {
    return data[input_x][input_y];
}
