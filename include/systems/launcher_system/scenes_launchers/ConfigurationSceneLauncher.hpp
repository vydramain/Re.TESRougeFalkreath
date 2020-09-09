//
// Created by vydra on 9/5/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/GameConfigurationData.hpp"
#include "entities/scenes_entities/SceneType.hpp"
#include "entities/scenes_entities/configuration_scene/ConfigurationScene.hpp"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"

class ConfigurationSceneLauncher : public IControl {
 private:
  GameConfigurationData * settings_data;
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit ConfigurationSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type,
                                 GameConfigurationData *input_settings_data);
  ~ConfigurationSceneLauncher() override;

  void execute() override;
};
