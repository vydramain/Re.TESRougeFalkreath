//
// Created by vydra on 15.07.2020.
//

#include "gsm/game_states/global_game_states/game_loop_state.h"

game_loop_state::game_loop_state() {
    input = new input_key();
    render = new game_loop_render();
}

game_loop_state::~game_loop_state() {
    delete input;
    delete render;
}

void game_loop_state::run() {
    render->render();
    do {
        input->update();

        render->render();
    } while(!(input->is_exit() || input->is_button_esc() || input->is_enter()));
}
