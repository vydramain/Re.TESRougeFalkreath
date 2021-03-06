//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>
#include <string>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/launcher_system/data/GameConfigurationData.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"
#include "systems/launcher_system/data/ParameterQueryDataSet.hpp"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlMap.h"
#include "systems/scenes_systems/game_loop_systems/controls/IGLControl.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/WorldSystem.hpp"

class GameLoopScene : public IMainScene {
 private:
  GameConfigurationData *settings_data = nullptr;
  IRenderSystem *render_system = nullptr;
  IWorldSystem *world_system = nullptr;

  ParameterQueryDataSet *data;

 public:
  explicit GameLoopScene(IRenderSystem *input_render_system, GameConfigurationData *input_settings_data);
  ~GameLoopScene() override;

  void run() override;
};
