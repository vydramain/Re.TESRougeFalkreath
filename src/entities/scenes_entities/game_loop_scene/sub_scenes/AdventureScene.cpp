//
// Created by vydra on 7/30/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/AdventureScene.h"

AdventureScene::AdventureScene(IWorldSystem *input_world_system)
    : IScene("AdventureScene") {
  gla_input = new GLAControls(input_world_system);
  ai_system = new SentientsAISystem(input_world_system);
}

AdventureScene::~AdventureScene() {
  delete gla_input;
  delete ai_system;
}

IControl *AdventureScene::get_control() {
  return control;
}

void AdventureScene::run() {
  control = gla_input->update();
  control->execute();
  ai_system->update();
}
