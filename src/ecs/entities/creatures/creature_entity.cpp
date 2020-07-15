//
// Created by vydra on 15.07.2020.
//

#include "ecs/entities/creatures/creature.h"

char *creature::get_name() const {
    return name;
}

unsigned int creature::get_current_x() const {
    return current_x;
}

unsigned int creature::get_current_y() const {
    return current_y;
}

unsigned creature::get_current_direction() const {
    return current_direction;
}

void creature::set_name(char *input_name) {
    name = input_name;
}

void creature::set_current_x(unsigned int input_x) {
    current_x = input_x;
}

void creature::set_current_y(unsigned int input_y) {
    current_y = input_y;
}

void creature::set_current_direction(direction input_direction) {
    current_direction = input_direction;
}

void creature::go_up() {
    current_direction = DIRECTION_UP;
    current_y--;
}

void creature::go_down() {
    current_direction = DIRECTION_DOWN;
    current_y++;
}

void creature::go_left() {
    current_direction = DIRECTION_LEFT;
    current_x--;
}

void creature::go_right() {
    current_direction = DIRECTION_RIGHT;
    current_x++;
}
