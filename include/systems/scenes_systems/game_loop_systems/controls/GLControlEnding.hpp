//
// Created by vydra on 8/17/20.
//

#pragma once

#include "entities/scenes_entities/game_loop_scene/sub_scenes/EndingScene.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/IGLControl.h"

class GLControlEnding : public IGLControl {
 private:
  IControl *last_control = nullptr;
  EndingScene *scene = nullptr;

 public:
  explicit GLControlEnding(IWorldSystem *input_location_system, ParameterQueryDataSet *input_ending_data)
      : IGLControl("GLControlEnding") {
    scene = new EndingScene(input_location_system, input_ending_data);
  }
  ~GLControlEnding() override {
    delete scene;
  }

  IControl *get_last_executed_control() override {
    return last_control;
  }

  void execute() override {
    scene->run();
    last_control = scene->get_last_control();
  }
};
