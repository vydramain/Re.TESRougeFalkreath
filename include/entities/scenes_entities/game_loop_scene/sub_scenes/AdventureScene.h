//
// Created by vydra on 7/30/20.
//

#pragma once

#include "entities/scenes_entities/IScene.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControls.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/ai_systems/IArctificialIntelligence.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/ai_systems/sentients_ai_system/SentientsAISystem.hpp"

class AdventureScene : public IScene {
 private:
  GLAControls *gla_input = nullptr;
  IControl *control = nullptr;

  IArtificialIntelligence *ai_system = nullptr;

 public:
  explicit AdventureScene(IWorldSystem *input_world_system);
  ~AdventureScene() override;

  IControl *get_control();

  void run() override;
};
