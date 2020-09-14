//
// Created by vydra on 9/14/20.
//

#pragma once

#include "entities/scenes_entities/IScene.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControls.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class CombatScene : public IScene {
 private:
  GLCControls *glc_input;
  IControl *control = nullptr;

 public:
  explicit CombatScene(IWorldSystem *input_world_system);
  ~CombatScene() override;

  IControl *get_control();

  void run() override;
};