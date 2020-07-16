//
// Created by vydra on 15.07.2020.
//

#include "ecs/components/render_component/game_loop_render.h"

game_loop_render::game_loop_render(const location_entity *input_location, const creatures_entity *input_creatures) {
    terminal_open();
    terminal_set("window: title='re.TESFalkreath', cellsize=8x15, size=100x40, fullscreen=true;");
    terminal_layer(0);
    terminal_clear();
    terminal_refresh();

    location = input_location;
    creatures = input_creatures;
    target = creatures->get_creature(0);

    if(target->get_current_x() < world_edge_x / 2){
        last_x = 0;
    } else {
        last_x = target->get_current_x() - world_edge_x / 2;
    }
    if(target->get_current_y() < world_edge_y / 2) {
        last_y = 0;
    } else {
        last_y = target->get_current_y() - world_edge_y / 2;
    }
}

game_loop_render::~game_loop_render() {
    terminal_clear();
    terminal_close();

    location = nullptr;
    creatures = nullptr;
}

void game_loop_render::set_target_creature(const creature_entity *input_target) {
    target = input_target;
}


void game_loop_render::clear_all() {
    terminal_clear();
}

void game_loop_render::clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
    terminal_clear_area(in_x, in_y, out_x, out_y);
}

void game_loop_render::view_message(const char *input_first_string, const char *input_second_string, unsigned in_x,
                                    unsigned in_y,
                                    unsigned out_x, unsigned out_y) {
    // cleaning up area_entity for message
    for (unsigned j = 0; j < out_y - in_y; j++) {
        for (unsigned i = 0; i < out_x - in_x; i++) {
            terminal_put(in_x + i, in_y + j, ' ');
        }
    }

    // draw borders
    for (unsigned j = 0; j < out_y - in_y; j++) {
        terminal_put(in_x, in_y + j + 1, '|');
        terminal_put(out_x, in_y + j, '|');
    }
    for (unsigned i = 0; i < out_x - in_x; i++) {
        terminal_put(in_x + i, in_y, '-');
        terminal_put(in_x + i + 1, out_y, '-');
    }

    terminal_print(in_x + 2, in_y + 2, input_first_string);
    terminal_print(in_x + 2, in_y + 3, input_second_string);
}

void game_loop_render::view_choice(const char *title, const char **input_choices,
                                   unsigned input_count_choices, unsigned highlighted_choice,
                                   unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
    for (unsigned ii(0); ii < (out_y - in_y); ii++) {
        for (unsigned i(0); i < (out_x - in_x); i++) {
            terminal_put(in_x + i, in_y + ii, ' ');
        }
    }

    for (unsigned ii(0); ii < (out_y - in_y); ii++) {
        terminal_put(in_x, in_y + 1 + ii, '|');
        terminal_put(out_x, in_y + ii, '|');
    }
    for (unsigned i(0); i < (out_x - in_x); i++) {
        terminal_put(in_x + i, in_y, '-');
        terminal_put(in_x + 1 + i, out_y, '-');
    }

    terminal_print(in_x + 7, in_y + 2, title);
    for (unsigned i(1); i < input_count_choices + 1; i++) {
        if (highlighted_choice == i) {
            terminal_print(in_x + 3, in_y + 3 + i, "-->");
        }
        terminal_print(in_x + 7, in_y + 3 + i, input_choices[i - 1]);
    }
}


unsigned game_loop_render::calc_camera_position_x(const unsigned input_x) {
    unsigned screen_place_x = last_x;

    if (input_x < world_edge_x / 4) {
        screen_place_x = 0;
        last_x = input_x;
    }
    if (location->get_size_x() - input_x < world_edge_x / 4) {
        screen_place_x = location->get_size_x() - world_edge_x;
        last_x = ((world_edge_x / 4) * 3) + location->get_size_x() - input_x;
    }
    if (input_x >= world_edge_x / 4 && location->get_size_x() - input_x >= world_edge_x / 4) {
        if (last_x > input_x && last_x + 1 < ((world_edge_x / 4) * 3)) {
            screen_place_x = last_x++;
        }
        if (last_x < input_x && last_x - 1 < world_edge_x / 4) {
            screen_place_x = last_x--;
        }
    }
    return screen_place_x;
}

unsigned game_loop_render::calc_camera_position_y(const unsigned input_y) {
    unsigned screen_place_y = last_y;

    if (input_y < world_edge_y / 4) {
        screen_place_y = 0;
        last_y = input_y;
    }
    if (location->get_size_y() - input_y < world_edge_y / 4) {
        screen_place_y = location->get_size_y() - world_edge_y;
        last_y = ((world_edge_y / 4) * 3) + location->get_size_y() - input_y;
    }
    if (input_y >= world_edge_y / 4 && location->get_size_y() - input_y >= world_edge_y / 4) {
        if (last_y > input_y && last_y + 1 < ((world_edge_y / 4) * 3)) {
            screen_place_y = last_y++;
        }
        if (last_y < input_y && last_y - 1 < world_edge_y / 4) {
            screen_place_y = last_y--;
        }
    }
    return screen_place_y;
}


void game_loop_render::paint_symbol(wchar_t symbol) {
    switch (symbol) {
        case '~': {
            terminal_color(0xcc00ffff);
            break;
        }
        case ';':
        case '+':
        case '-':
        case '?':
        case ':':
        case 'J':
        case '`':
        case 'x':
        case '9': {
            terminal_color(0xff26cf26);
            break;
        }
        case '[':
        case ']':
        case '_': {
            terminal_color(0xff7f7f7f);
            break;
        }
        case 'W':
        case 'w':
        case 'V': {
            terminal_color(0xffe3c347);
            break;
        }
        case '"':
        case '|':
        case '=':
        case '>':
        case '^':
        case 'v':
        case '<': {
            terminal_color(0xffba7300);
            break;
        }
        case '#': {
            terminal_color(0xff666666);
            break;
        }
        case 'L': {
            terminal_color(0xffabff00);
            break;
        }
        case 't': {
            terminal_color(0xffb2b2b2);
            break;
        }
        case 'Z': {
            terminal_color(0xff888800);
            break;
        }
        case '$': {
            terminal_color(0xffffff00);
            break;
        }
        case 'Q': {
            terminal_color(0xff44eedd);
            break;
        }
        default: {
            terminal_color(0xff4c4c4c);
            break;
        }
    }
}

void game_loop_render::view_location() {
    if (target) {
        unsigned target_x = calc_camera_position_x(target->get_current_x());
        unsigned target_y = calc_camera_position_y(target->get_current_y());

        view_area(target_x, target_y);
        view_creatures(target_x, target_y);
        view_items(target_x, target_y);
    } else {
        view_message("target missed!", "", 0, 0, world_edge_x, world_edge_y);
    }
}

void game_loop_render::view_area(unsigned input_camera_x, unsigned input_camera_y) {
    char temp;
    for (int ii = 0; ii < world_edge_y; ii++) {
        for (int i = 0; i < world_edge_x; i++) {
            terminal_color(0xaaffffff);
            terminal_layer(1);
            temp = location->get_current_area()->get_cell(input_camera_x + i, input_camera_y + ii);
            paint_symbol(temp);
            terminal_put(i, ii, temp);
        }
    }
}

void game_loop_render::view_creatures(unsigned input_camera_x, unsigned input_camera_y) {
    const creature_entity *creature;
    for (unsigned i = 0; i < creatures->get_size(); i++) {
        creature = creatures->get_creature(i);
        unsigned creature_x = creature->get_current_x();
        unsigned creature_y = creature->get_current_y();

        if ((creature_x >= input_camera_x &&
             creature_x < input_camera_x + world_edge_x) &&
            (creature_y >= input_camera_y &&
             creature_y < input_camera_y + world_edge_y)) {
            terminal_color(0xffFFFFFF);
            terminal_layer(2);
            terminal_put(creature_x - input_camera_x, creature_y - input_camera_y, 'i');
        }
    }
}


/*
void game_loop_render::view_player() {
    int screen_place_x = calc_camera_position_x();
    int screen_place_y = calc_camera_position_y();

    terminal_layer(4);
    terminal_color(0xFFFFFFFF);
    terminal_put_ext(screen_place_x, screen_place_y, 0, -1, 'i');
}
*/

void game_loop_render::view_hud() {
    terminal_layer(5);
    terminal_color(0xffffffff);
    for (int i = 0; i < world_edge_y; i++) {
        terminal_print(world_edge_x, i, "|");
    }

    for (int i = 0; i < SCREENMODE_X - world_edge_x; i++) {
        terminal_print(world_edge_x + i + 1, 9, "_");
        terminal_print(world_edge_x + i + 1, world_edge_y - 5, "_");
    }

    terminal_print(world_edge_x + 1, world_edge_y - 3, "Координаты:");

    terminal_print(world_edge_x + 1, 1, "Имя:");
    terminal_print(world_edge_x + 1, 2, "Раса:");
    terminal_print(world_edge_x + 1, 3, "Статус:");

    terminal_color(0xFFFF4444);
    terminal_print(world_edge_x + 1, 4, "ОЗ:");
    terminal_color(0xFF44ff44);
    terminal_print(world_edge_x + 1, 5, "ОД:");
    terminal_color(0xFF6666FF);
    terminal_print(world_edge_x + 1, 6, "OМ:");
}

void game_loop_render::render() {
    clear_all();
    view_location();
    view_hud();
    terminal_refresh();
}
