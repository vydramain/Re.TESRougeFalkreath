//
// Created by vydra on 15.07.2020.
//

#include <ecs/systems/scenes_system/MainLoopScene.h>

MainLoopScene::MainLoopScene(const char* input_area_name, area_entity *input_area, creature_entity *input_player) {
    auto *creatures = new creatures_entity(1);
    creatures->put_creature(*input_player);
    location = new location_entity(input_area_name, input_area, creatures);
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
        input->update();

        if(input->is_up()) {
            location->get_current_creatures()->get_creature(0)->go_up();
        }

        if(input->is_down()) {
            location->get_current_creatures()->get_creature(0)->go_down();
        }

        if(input->is_left()) {
            location->get_current_creatures()->get_creature(0)->go_left();
        }

        if(input->is_right()) {
            location->get_current_creatures()->get_creature(0)->go_right();
        }

        render->render();
    } while(!(input->is_exit() || input->is_button_esc() || input->is_enter()));
}
