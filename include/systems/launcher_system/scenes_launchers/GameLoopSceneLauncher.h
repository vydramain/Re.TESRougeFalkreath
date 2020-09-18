//
// Created by vydra on 8/9/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/SceneType.hpp"
#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "systems/IControl.h"
#include "systems/launcher_system/data/GameConfigurationData.hpp"
#include "systems/render_systems/IRenderSystem.h"

class GameLoopSceneLauncher : public IControl {
 private:
  GameConfigurationData * settings_data;
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit GameLoopSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type,
                                 GameConfigurationData *input_settings_data);
  ~GameLoopSceneLauncher() override;

  void execute() override;
};
