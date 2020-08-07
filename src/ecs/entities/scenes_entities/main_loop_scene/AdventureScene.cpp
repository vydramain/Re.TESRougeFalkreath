//
// Created by vydra on 7/30/20.
//

#include "ecs/entities/scenes_entities/main_loop_scene/AdventureScene.h"

void AdventureScene::run() {
  last_control = mla_input->update();
  last_control->execute();
}
