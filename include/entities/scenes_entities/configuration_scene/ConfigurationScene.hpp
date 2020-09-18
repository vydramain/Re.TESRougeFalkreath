//
// Created by vydra on 9/5/20.
//

#pragma once

#include <cstring>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/IControl.h"
#include "systems/launcher_system/data/GameConfigurationData.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/configuration_systems/controls/COControls.h"

class ConfigurationScene : public IMainScene {
 private:
  GameConfigurationData *global_configuration_data = nullptr;
  ParameterQueryData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  COControls *co_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit ConfigurationScene(IRenderSystem *input_render_system, GameConfigurationData *input_configuration_data);
  ~ConfigurationScene() override;

  unsigned get_highlighted() const;

  void run() override;
};