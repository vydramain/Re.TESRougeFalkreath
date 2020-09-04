//
// Created by vydra on 9/5/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/GameSettingsData.hpp"
#include "entities/scenes_entities/SceneType.hpp"
#include "entities/scenes_entities/settings_scene/SettingsScene.hpp"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"

class SettingsSceneLauncher : public IControl {
 private:
  GameSettingsData* settings_data;
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit SettingsSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type,
                                 GameSettingsData *input_settings_data);
  ~SettingsSceneLauncher() override;

  void execute() override;
};
