//
// Created by vydra on 7/30/20.
//

#pragma once

#include "entities/scenes_entities/IScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControls.h"
#include "systems/location_systems/LocationSystem.h"

class AdventureScene : public IScene {
 private:
  GLAControls *mla_input;
  IControl *last_control = nullptr;

 public:
  explicit AdventureScene(LocationSystem *input_location);
  ~AdventureScene() override;

  IControl *get_last_control();

  void run() override;
};
