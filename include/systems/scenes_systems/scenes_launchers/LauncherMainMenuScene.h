//
// Created by vydra on 8/9/20.
//

#pragma once

#include "entities/scenes_entities/main_menu_scene/MainMenuScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems/pseudo_log_systems/PseudoLogSystem.hpp"

class LauncherMainMenuScene : public IControl {
 private:
  IRenderSystem *render_system;
  unsigned *highlighted;

 public:
  explicit LauncherMainMenuScene(IRenderSystem *input_system, unsigned *input_pointer);
  ~LauncherMainMenuScene() override;

  void execute() override;
};