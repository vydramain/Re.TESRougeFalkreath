//
// Created by vydra on 8/17/20.
//

#pragma once

#include "entities/scenes_entities/game_loop_scene/sub_scenes/EndingScene.hpp"
#include "systems/controls_systems/game_loop_controls/IGLControl.h"
#include "systems/location_systems/LocationSystem.h"

class GLControlEnding : public IGLControl {
 private:
  IControl *last_control = nullptr;
  EndingScene *scene = nullptr;

 public:
  explicit GLControlEnding(LocationSystem *input_location_system, const unsigned input_count,
                           unsigned *input_highlighted) : IGLControl("GLControlEnding") {
    scene = new EndingScene(input_location_system, input_count, input_highlighted);
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