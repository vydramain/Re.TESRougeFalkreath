//
// Created by vydra on 12.07.2020.
//

#include "ecs/components/render_component/main_menu_render/main_menu_render.h"

main_menu_render::main_menu_render() {
    terminal_open();
    terminal_set("window: title='re.TESFalkreath', cellsize=8x15, size=28x17, fullscreen=true;");
    terminal_layer(0);
    terminal_refresh();
}

main_menu_render::~main_menu_render() {
    terminal_clear();
    terminal_close();
}

void main_menu_render::clear_all() {
    terminal_clear();
}

void main_menu_render::clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
    terminal_clear_area(in_x, in_y, out_x, out_y);
}

void main_menu_render::view_choice(const char *title, const char **input_choices,
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

void main_menu_render::render() {
    clear_all();
    view_choice(this->title, this->choices,
                this->count_choices, this->highlighted,
                0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1);
    terminal_refresh();
}
