//
// Created by vydra on 7/30/20.
//

#include "core/entities/scenes_entities/game_loop_scene/sub_scenes/AdventureScene.h"

AdventureScene::AdventureScene(Location *input_location)
    : IScene("AdventureScene"), mla_input(new GLAControls(input_location)) {}

AdventureScene::~AdventureScene() {
  delete mla_input;
}

IControl *AdventureScene::get_last_control() {
  return last_control;
}

void AdventureScene::run() {
  last_control = mla_input->update();
  last_control->execute();
}
