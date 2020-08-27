//
// Created by vydra on 12.07.2020.
//

#pragma once

#include <cstring>

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/scenes_controls/main_menu_controls/MMControls.h"
#include "systems/render_systems/IRenderSystem.h"

class MainMenuScene : public IMainScene {
 private:
  ParameterQueryData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  MMControls *mm_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit MainMenuScene(IRenderSystem *input_render_system);
  ~MainMenuScene() override;

  unsigned get_highlighted() const;

  void run() override;
};
