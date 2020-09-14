//
// Created by vydra on 7/30/20.
//

#pragma once

#include "entities/scenes_entities/IScene.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControls.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class AdventureScene : public IScene {
 private:
  GLAControls *gla_input;
  IControl *control = nullptr;

 public:
  explicit AdventureScene(IWorldSystem *input_world_system);
  ~AdventureScene() override;

  IControl *get_control();

  void run() override;
};
