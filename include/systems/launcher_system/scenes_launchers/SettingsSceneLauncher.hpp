//
// Created by vydra on 9/5/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/SceneType.hpp"
#include "entities/scenes_entities/settings_scene/SettingsScene.hpp"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"

class SettingsSceneLauncher : public IControl {
 private:
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit SettingsSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type);
  ~SettingsSceneLauncher() override;

  void execute() override;
};
