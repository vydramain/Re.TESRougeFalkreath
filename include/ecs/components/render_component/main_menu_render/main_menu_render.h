//
// Created by vydra on 12.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MAIN_MENU_RENDER_H
#define RE_TESROUGEFALKREATH_MAIN_MENU_RENDER_H

#include "BearLibTerminal.h"
#include "components/render_component/interface_render.h"

class main_menu_render : public interface_render {
private:
    const unsigned SCREENMODE_X = 28;
    const unsigned SCREENMODE_Y = 17;

    const char *const title = "Главное меню:";
    const char *choices[2] = {"Играть", "Выход"};
    const unsigned count_choices = 2;
    unsigned highlighted = 0;

public:
    main_menu_render();

    ~main_menu_render();

    void set_highlighted(unsigned int highlighted) {
        this->highlighted = highlighted;
    }

    static void clear_all();
    static void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);
    static void view_choice(const char *title, const char **input_choices,
                     unsigned input_count_choices, unsigned highlighted_choice,
                     unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);

    void render();
};

#endif //RE_TESROUGEFALKREATH_MAIN_MENU_RENDER_H
