//
// Created by vydra on 9/5/20.
//

#pragma once

#include <cstring>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/settings_systems/controls/SEControls.h"

class SettingsScene : public IMainScene {
 private:
  ParameterQueryData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  SEControls *s_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit SettingsScene(IRenderSystem *input_render_system);
  ~SettingsScene() override;

  unsigned get_highlighted() const;

  void run() override;
};