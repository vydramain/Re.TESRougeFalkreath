//
// Created by vydra on 15.07.2020.
//

#include "ecs/systems/render_system/game_loop_render.h"

game_loop_render::game_loop_render(const Location *input_location, const Creatures *input_creatures) {
    terminal_open();
    terminal_set("window: title='re.TESFalkreath', cellsize=8x15, size=100x40, fullscreen=true;");
    terminal_layer(0);
    terminal_clear();
    terminal_refresh();

    location = input_location;
    creatures = input_creatures;

    target = creatures->get_creature(0);

    new_camera_position_x();
    new_camera_position_y();
}

game_loop_render::~game_loop_render() {
    terminal_clear();
    terminal_close();

    location = nullptr;
    creatures = nullptr;
}

void game_loop_render::set_target_creature(const Creature *input_target) {
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
    // cleaning up Area for message
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

void game_loop_render::new_camera_position_x() {
    current_camera_x = target->get_current_x() - active_zone_in_x;
    if (target->get_current_x() < active_zone_in_x) {
        current_camera_x = 0;
    }
    if (location->get_size_x() - target->get_current_x() < active_zone_out_x) {
        current_camera_x = location->get_size_x() - passive_zone_out_x;
    }
}

void game_loop_render::new_camera_position_y() {
    current_camera_y = target->get_current_y() - active_zone_in_y;
    if (target->get_current_y() < active_zone_in_y) {
        current_camera_y = 0;
    }
    if (location->get_size_y() - target->get_current_y() < active_zone_out_y) {
        current_camera_y = location->get_size_y() - passive_zone_out_y;
    }
}

void game_loop_render::update_camera_position_x() {
    unsigned target_x = target->get_current_x();

    if (target_x < current_camera_x + active_zone_in_x || target_x > current_camera_x + active_zone_out_x) {
        if (target_x < current_camera_x + active_zone_in_x) {
            current_camera_x = target_x - active_zone_in_x;
            if (target_x < active_zone_in_x) {
                current_camera_x = 0;
            }
        }
        if (target_x > current_camera_x + active_zone_out_x) {
            current_camera_x = target_x - active_zone_out_x;
            if (target_x >= location->get_size_x() - active_zone_in_x) {
                current_camera_x = location->get_size_x() - passive_zone_out_x;
            }
        }
    }
}

void game_loop_render::update_camera_position_y() {
    unsigned target_y = target->get_current_y();

    if (target_y < current_camera_y + active_zone_in_y || target_y > current_camera_y + active_zone_out_y) {
        if (target_y < current_camera_y + active_zone_in_y) {
            current_camera_y = target_y - active_zone_in_y;
            if (target_y < active_zone_in_y) {
                current_camera_y = 0;
            }
        }
        if (target_y > current_camera_y + active_zone_out_y) {
            current_camera_y = target_y - active_zone_out_y;
            if (target_y >= location->get_size_y() - active_zone_in_y) {
                current_camera_y = location->get_size_y() - passive_zone_out_y;
            }
        }
    }
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

void game_loop_render::render_location() {
    if (target) {
        update_camera_position_x();
        update_camera_position_y();

        render_area(current_camera_x, current_camera_y);
        render_creatures(current_camera_x, current_camera_y);
        render_items(current_camera_x, current_camera_y);
    } else {
        view_message("target missed!", "", 0, 0, passive_zone_out_x, passive_zone_out_y);
    }
}

void game_loop_render::render_area(unsigned input_camera_x, unsigned input_camera_y) {
    char temp;
    for (int ii = 0; ii < passive_zone_out_y; ii++) {
        for (int i = 0; i < passive_zone_out_x; i++) {
            terminal_color(0xaaffffff);
            terminal_layer(1);
            temp = location->get_current_area()->get_cell(input_camera_x + i, input_camera_y + ii);
            paint_symbol(temp);
            terminal_put(i, ii, temp);
        }
    }
}

void game_loop_render::render_creatures(unsigned input_camera_x, unsigned input_camera_y) {
    const Creature *creature;
    for (unsigned i = 0; i < creatures->get_size(); i++) {
        creature = creatures->get_creature(i);
        unsigned creature_x = creature->get_current_x();
        unsigned creature_y = creature->get_current_y();

        if ((creature_x >= input_camera_x &&
             creature_x < input_camera_x + passive_zone_out_x) &&
            (creature_y >= input_camera_y &&
             creature_y < input_camera_y + passive_zone_out_y)) {
            terminal_color(0xffFFFFFF);
            terminal_layer(2);
            terminal_put(creature_x - input_camera_x, creature_y - input_camera_y, 'i');
        }
    }
}

void game_loop_render::render_hud() {
    terminal_layer(5);
    terminal_color(0xffffffff);
    for (int i = 0; i < passive_zone_out_y; i++) {
        terminal_print(passive_zone_out_x, i, "|");
    }

    for (int i = 0; i < SCREENMODE_X - passive_zone_out_x; i++) {
        terminal_print(passive_zone_out_x + i + 1, 9, "_");
        terminal_print(passive_zone_out_x + i + 1, passive_zone_out_y - 5, "_");
    }

    terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 3, "Координаты:");

    terminal_print(passive_zone_out_x + 1, 1, "Имя:");
    terminal_print(passive_zone_out_x + 1, 2, "Раса:");
    terminal_print(passive_zone_out_x + 1, 3, "Статус:");

    terminal_color(0xFFFF4444);
    terminal_print(passive_zone_out_x + 1, 4, "ОЗ:");
    terminal_color(0xFF44ff44);
    terminal_print(passive_zone_out_x + 1, 5, "ОД:");
    terminal_color(0xFF6666FF);
    terminal_print(passive_zone_out_x + 1, 6, "OМ:");
}

void game_loop_render::render() {
    clear_all();
    render_location();
    render_hud();
    terminal_refresh();
}
