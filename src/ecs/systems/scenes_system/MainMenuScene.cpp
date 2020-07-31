//
// Created by vydra on 12.07.2020.
//

#include <cstring>
#include <ecs/systems/scenes_system/MainMenuScene.h>

void MainMenuScene::run() {
    do {
        render->view_choice(title, choices, count_choices, highlighted);
        render->render();

        last_control = mm_input->update();
        last_control->execute();
    } while (std::strcmp(last_control->get_name(), "MMControlSelectExit") != 0 && std::strcmp(last_control->get_name(), "MMControlSelectEnter") != 0);
}
