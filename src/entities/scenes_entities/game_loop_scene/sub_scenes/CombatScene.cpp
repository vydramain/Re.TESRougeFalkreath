//
// Created by vydra on 9/15/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/CombatScene.hpp"

CombatScene::CombatScene(IWorldSystem *input_world_system) {
  glc_input = new GLCControls(input_world_system);
}

CombatScene::~CombatScene() {
    delete glc_input;
}

IControl* CombatScene::get_control() {
  return control;
}

void CombatScene::run() {
  control = glc_input->update();
  control->execute();
}
