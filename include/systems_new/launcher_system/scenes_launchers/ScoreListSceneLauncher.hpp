//
// Created by vydra on 8/19/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/score_list_scene/ScoreListScene.hpp"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "entities/scenes_entities/SceneType.hpp"

class ScoreListSceneLauncher : public IControl {
 private:
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit ScoreListSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type);
  ~ScoreListSceneLauncher() override;

  void execute() override;
};
