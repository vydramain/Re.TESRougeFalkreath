//
// Created by vydra on 15.07.2020.
//

#include "gsm/game_states/global_game_states/game_loop_state.h"

game_loop_state::game_loop_state(char* input_area_name, area_entity *input_area, creature_entity *input_player) {
    input = new controls_component();
    render = new game_loop_render(location, creatures);

    location = new location_entity(input_area_name, input_area);
    creatures = new creatures_entity(1);
    creatures->put_creature(*input_player);
    delete input_player;
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
