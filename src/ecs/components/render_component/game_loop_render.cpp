//
// Created by vydra on 15.07.2020.
//

#include "ecs/components/render_component/game_loop_render.h"

game_loop_render::game_loop_render() {
    terminal_open();
    terminal_set("window: title='re.TESFalkreath', cellsize=8x15, size=100x40, fullscreen=true;");
    terminal_layer(0);
    terminal_clear();
    terminal_refresh();
}

game_loop_render::~game_loop_render() {
    terminal_clear();
    terminal_close();
}

void game_loop_render::clear_all() {
    terminal_clear();
}

void game_loop_render::clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
    terminal_clear_area(in_x, in_y, out_x, out_y);
}

void game_loop_render::view_message(const char *input_first_string, const char *input_second_string, unsigned in_x, unsigned in_y,
                                   unsigned out_x, unsigned out_y) {
    // cleaning up area for message
    for (unsigned j = 0; j < out_y - in_y; j++) {
        for(unsigned i = 0; i < out_x - in_x; i++) {
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

void game_loop_render::view_player() {
    terminal_layer(4);
    terminal_color(0xFFFFFFFF);
    terminal_put_ext(30, 20, 0, -1, 'i');
}

void game_loop_render::view_hud() {
    terminal_layer(5);
    terminal_color(0xffffffff);
    for (int i = 0; i < world_edge_y; i++) {
        terminal_print(world_edge_x, i, "|");
    }

    for(int i = 0; i < SCREENMODE_X - world_edge_x; i++){
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
    view_player();
    view_hud();
    terminal_refresh();
}
