//
// Created by vydra on 9/5/20.
//

#pragma once

#include <cstring>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/GameSettingsData.hpp"
#include "entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/settings_systems/controls/SEControls.h"

class SettingsScene : public IMainScene {
 private:
  GameSettingsData* global_settings_data = nullptr;
  ParameterQueryData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  SEControls *s_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit SettingsScene(IRenderSystem *input_render_system, GameSettingsData *input_settings_data);
  ~SettingsScene() override;

  unsigned get_highlighted() const;

  void run() override;
};