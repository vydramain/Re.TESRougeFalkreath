//
// Created by vydra on 8/9/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems_new/launcher_system/scenes_launchers/ScenesLaunchersManager.h"

class GameLoopSceneLauncher : public IControl {
 private:
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit GameLoopSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type);
  ~GameLoopSceneLauncher() override;

  void execute() override;
};
