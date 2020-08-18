//
// Created by vydra on 7/30/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/AdventureScene.h"

AdventureScene::AdventureScene(LocationSystem *input_location)
    : IScene("AdventureScene"), mla_input(new GLAControls(input_location)) {}

AdventureScene::~AdventureScene() {
  delete mla_input;
}

IControl *AdventureScene::get_control() {
  return control;
}

void AdventureScene::run() {
  control = mla_input->update();
  control->execute();
}
