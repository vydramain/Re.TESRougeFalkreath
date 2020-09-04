//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>
#include <string>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/render_systems/IRenderSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/controls/GLControlMap.h"
#include "systems_new/scenes_systems/game_loop_systems/controls/IGLControl.h"

class GameLoopScene : public IMainScene {
 private:
  IRenderSystem *render_system;
  LocationSystem *location_system = nullptr;

  ParameterQueryData *ending_data;

 public:
  explicit GameLoopScene(IRenderSystem *input_render_system);
  ~GameLoopScene() override;

  void run() override;
};
