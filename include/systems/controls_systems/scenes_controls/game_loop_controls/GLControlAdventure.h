//
// Created by vydra on 7/31/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/game_loop_scene/sub_scenes/AdventureScene.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/IGLControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLControlAdventure : public IGLControl {
 private:
  IControl *adventure_executed_control = nullptr;
  AdventureScene *scene;

 public:
  explicit GLControlAdventure(LocationSystem *input_location)
      : IGLControl("GLControlAdventure"), scene(new AdventureScene(input_location)) {}
  ~GLControlAdventure() override {
    delete scene;
  }

  IControl *get_last_executed_control() override {
    return adventure_executed_control;
  }

  void execute() override {
    scene->run();
    adventure_executed_control = scene->get_control();
  }
};
