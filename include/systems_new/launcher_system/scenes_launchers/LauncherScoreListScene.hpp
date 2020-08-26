//
// Created by vydra on 8/19/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/score_list_scene/ScoreListScene.hpp"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"

class LauncherScoreListScene : public IControl {
 private:
  IRenderSystem *render_system = nullptr;
  unsigned *highlighted;

 public:
  explicit LauncherScoreListScene(IRenderSystem *input_render_system, unsigned *input_pointer);
  ~LauncherScoreListScene() override;

  void execute() override;
};
