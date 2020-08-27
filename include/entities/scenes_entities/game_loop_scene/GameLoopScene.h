//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>
#include <string>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/MenuData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlMap.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/IGLControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GameLoopScene : public IMainScene {
 private:
  IRenderSystem *render_system;
  LocationSystem *location_system = nullptr;

  MenuData *ending_data;

 public:
  explicit GameLoopScene(IRenderSystem *input_render_system);
  ~GameLoopScene() override;

  void run() override;
};
