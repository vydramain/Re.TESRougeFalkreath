//
// Created by vydra on 8/17/20.
//

#pragma once

#include <cstring>

#include "entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IScene.h"
#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/ending_controls/GLEControls.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class EndingScene : public IScene {
 private:
  GLEControls *gle_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit EndingScene(IWorldSystem *input_location, ParameterQueryData *input_ending_data);
  ~EndingScene() override;

  IControl *get_last_control();

  void run() override;
};