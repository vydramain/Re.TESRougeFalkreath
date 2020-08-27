//
// Created by vydra on 8/19/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/scenes_entities/SceneType.hpp"
#include "entities/scenes_entities/statistics_scene/StatisticsScene.hpp"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"

class StatisticsSceneLauncher : public IControl {
 private:
  IRenderSystem *render_system;
  SceneType *scene_type;

 public:
  explicit StatisticsSceneLauncher(IRenderSystem *input_render_system, SceneType *input_scene_type);
  ~StatisticsSceneLauncher() override;

  void execute() override;
};
