//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/locations_entities/location_entity.h"

const char *location_entity::get_name() const {
    return name;
}

unsigned int location_entity::get_size_x() const {
    return size_x;
}

unsigned int location_entity::get_size_y() const {
    return size_y;
}

area_entity *location_entity::get_current_area() const {
    return current_area;
}

creatures_entity *location_entity::get_current_creatures() const {
    return current_creatures;
}


void location_entity::set_name(const char *input_name) {
    location_entity::name = input_name;
}

void location_entity::set_size_x(unsigned int input_x) {
    size_x = input_x;
}

void location_entity::set_size_y(unsigned int input_y) {
    size_y = input_y;
}

void location_entity::set_current_area(area_entity *input_area) {
    current_area = input_area;
}

void location_entity::set_current_creatures(creatures_entity *input_creatures) {
    current_creatures = input_creatures;
}