//
// Created by vydra on 7/31/20.
//

#pragma once

#include "core/entities/scenes_entities/game_loop_scene/sub_scenes/AdventureScene.h"
#include "core/systems/controls_system/game_loop_controls/IGLControl.h"

class GLControlAdventure : public IGLControl {
 private:
  IControl *last_control = nullptr;
  AdventureScene *scene;

 public:
  explicit GLControlAdventure(LocationSystem *input_location)
      : IGLControl("GLControlAdventure"), scene(new AdventureScene(input_location)) {}
  ~GLControlAdventure() override {
    delete scene;
  }

  IControl *get_last_control() override {
    return last_control;
  }

  void execute() override {
    scene->run();
    last_control = scene->get_last_control();
  }
};
