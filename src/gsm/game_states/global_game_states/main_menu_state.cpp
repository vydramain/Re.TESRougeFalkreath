//
// Created by vydra on 12.07.2020.
//

#include "gsm/game_states/global_game_states/main_menu_state.h"

void main_menu_state::update() const {
    const char *const title = "Главное меню:";
    const char *choices[2] = {"Играть", "Выход"};
    const unsigned count_choices = 2;
    unsigned highlighted = 0;

    render->view_choice(title, choices, count_choices, highlighted);
    render->render();
    do {
        input->update();
        if((input->is_up() || input->is_button_w()) && highlighted > 1){
            highlighted--;
        }
        if((input->is_down() || input->is_button_s()) && highlighted < count_choices) {
            highlighted++;
        }
        render->view_choice(title, choices, count_choices, highlighted);
        render->render();
    } while(!(input->is_exit() || input->is_button_esc()));
}
