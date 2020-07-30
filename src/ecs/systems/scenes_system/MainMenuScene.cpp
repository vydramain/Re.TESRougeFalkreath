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
}
