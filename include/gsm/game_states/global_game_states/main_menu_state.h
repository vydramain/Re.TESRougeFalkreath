//
// Created by vydra on 12.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H
#define RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H

#include "gsm/game_states/global_game_states/global_game_state.h"
#include "ecs/components/controls_component/input_key.h"
#include "ecs/components/render_component/main_menu_render/main_menu_render.h"

class main_menu_state : public global_game_state {
private:
    input_key *input;
    main_menu_render *render;

public:
    explicit main_menu_state() : global_game_state("main_menu") {
        input = new input_key();
        render = new main_menu_render();
    }
    ~main_menu_state() {
        delete input;
        delete render;
    }

    void update() const;
};

#endif //RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H
