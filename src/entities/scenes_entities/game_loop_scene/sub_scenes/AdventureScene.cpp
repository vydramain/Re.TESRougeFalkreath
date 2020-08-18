//
// Created by vydra on 7/30/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/AdventureScene.h"

AdventureScene::AdventureScene(LocationSystem *input_location)
    : IScene("AdventureScene"), gla_input(new GLAControls(input_location)) {}

AdventureScene::~AdventureScene() {
  delete gla_input;
}

IControl *AdventureScene::get_control() {
  return control;
}

void AdventureScene::run() {
  control = gla_input->update();
  control->execute();
}
