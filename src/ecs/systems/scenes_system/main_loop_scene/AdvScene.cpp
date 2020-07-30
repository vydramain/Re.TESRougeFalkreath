//
// Created by vydra on 7/30/20.
//

#include <ecs/systems/scenes_system/main_loop_scene/AdvScene.h>


void AdvScene::run() {
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
}