//
// Created by vydra on 8/9/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/SceneType.hpp"
#include "entities/scenes_entities/main_menu_scene/MainMenuScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems_new/render_systems/IRenderSystem.h"

class MainMenuSceneLauncher : public IControl {
 private:
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit MainMenuSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type);
  ~MainMenuSceneLauncher() override;

  void execute() override;
};
