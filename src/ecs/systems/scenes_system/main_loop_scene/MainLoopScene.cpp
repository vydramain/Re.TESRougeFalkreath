//
// Created by vydra on 15.07.2020.
//

#include <ecs/systems/scenes_system/main_loop_scene/MainLoopScene.h>

MainLoopScene::MainLoopScene(const char* input_area_name, Map *input_area, Creature *input_player) {
    auto *creatures = new Creatures(1);
    creatures->put_creature(*input_player);
    location = new Location(input_area_name, input_area, creatures);
    delete input_player;

    input = new Controls();
    render = new game_loop_render(location, creatures);
}

MainLoopScene::~MainLoopScene() {
    delete input;
    delete render;
}

void MainLoopScene::run() {
    render->render();
    do {
        auto *adventure = new AdvScene(input, location);
        adventure->run();
        render->render();
    } while(!(input->is_exit() || input->is_button_esc() || input->is_enter()));
}
