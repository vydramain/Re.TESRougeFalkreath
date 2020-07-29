//
// Created by vydra on 12.07.2020.
//

#include <ecs/systems/scenes_system/MainMenuScene.h>

void MainMenuScene::run() {
    const char *const title = "Главное меню:";
    const char *choices[2] = {"Играть", "Выход"};
    const unsigned count_choices = 2;

    render->view_choice(title, choices, count_choices, highlighted);
    render->render();
    do {
        input->update();
        if(input->is_up() && highlighted > 1) {
            highlighted--;
        }
        if(input->is_down() && highlighted < count_choices) {
            highlighted++;
        }
        render->view_choice(title, choices, count_choices, highlighted);
        render->render();
    } while(!(input->is_exit() || input->is_button_esc() || input->is_enter()));
}