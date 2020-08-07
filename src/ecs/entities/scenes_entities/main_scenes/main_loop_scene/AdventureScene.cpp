//
// Created by vydra on 7/30/20.
//

#include "ecs/entities/scenes_entities/main_scenes/main_loop_scene/AdventureScene.h"

AdventureScene::AdventureScene(Location *input_location)
    : IScene("AdventureScene"), location(input_location), mla_input(new MLAControls(input_location)) {}

AdventureScene::~AdventureScene() {
  location = nullptr;
  delete mla_input;
}

IControl *AdventureScene::get_last_control() {
  return last_control;
}

void AdventureScene::run() {
  last_control = mla_input->update();
  last_control->execute();
}
