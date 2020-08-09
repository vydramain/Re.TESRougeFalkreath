//
// Created by vydra on 7/30/20.
//

#pragma once

#include "core/entities/scenes_entities/IScene.h"
#include "core/systems/controls_system/game_loop_controls/sub_controls/adventure_controls/GLAControls.h"
#include "ecs/systems/location_system/LocationSystem.h"

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
