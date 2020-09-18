//
// Created by vydra on 9/18/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/game_loop_scene/sub_scenes/CombatScene.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/IGLControl.h"

class GLControlCombat : public IGLControl {
 private:
  IControl *combat_executed_control = nullptr;
  CombatScene *scene;

 public:
  explicit GLControlCombat(IWorldSystem *input_world_system, ParameterQueryDataSet* input_data)
      : IGLControl("GLControlCombat"), scene(new CombatScene(input_world_system, input_data)) {}
  ~GLControlCombat() override {
    delete scene;
  }

  IControl *get_last_executed_control() override {
    return combat_executed_control;
  }

  void execute() override {
    scene->run();
    combat_executed_control = scene->get_control();
  }
};
