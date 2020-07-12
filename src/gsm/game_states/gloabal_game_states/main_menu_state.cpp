//
// Created by vydra on 12.07.2020.
//

#include "gsm/game_states/global_game_states/main_menu_state.h"

void main_menu_state::update() const {
    input->update();
    if(input->is_up()){
        render->set_highlighted(1);
    }
    if(input->is_down()){
        render->set_highlighted(2);
    }
    if(input->is_exit() || input->is_button_esc()){
        is_closed_ = true;
    }
    render->render();
}