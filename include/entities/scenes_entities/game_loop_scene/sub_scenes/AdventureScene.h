//
// Created by vydra on 7/30/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "entities/scenes_entities/IScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems_new/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControls.h"

class AdventureScene : public IScene {
 private:
  GLAControls *gla_input;
  IControl *control = nullptr;

 public:
  explicit AdventureScene(LocationSystem *input_location);
  ~AdventureScene() override;

  IControl *get_control();

  void run() override;
};
