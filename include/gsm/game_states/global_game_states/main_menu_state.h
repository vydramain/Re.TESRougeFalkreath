//
// Created by vydra on 12.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H
#define RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H

#include "gsm/game_states/global_game_states/global_game_state.h"
#include "ecs/systems/render_system/main_menu_render.h"
#include "ecs/systems/controls_system/controls.h"


class main_menu_state : public global_game_state {
private:
    controls *input;
    main_menu_render *render;

    unsigned highlighted = 0;

public:
    explicit main_menu_state() : global_game_state("main_menu") {
        render = new main_menu_render();
        input = new controls();
    }
    ~main_menu_state() {
        delete input;
        delete render;
    }

    void run() override;
};

#endif //RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H
