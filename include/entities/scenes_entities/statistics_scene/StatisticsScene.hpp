//
// Created by vydra on 8/19/20.
//

#pragma once

#include <cstdio>

#include "entities/render_entities/data/StringsListData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/statistics_systems/IStatisticsSystem.hpp"
#include "systems/scenes_systems/statistics_systems/StdStatisticsSystem.hpp"
#include "systems/scenes_systems/statistics_systems/controls/SControls.hpp"

class StatisticsScene : public IMainScene {
 private:
  StringsListData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  SControls *sl_input = nullptr;
  IControl *last_control = nullptr;

  IStatisticsSystem *score_system = nullptr;

 public:
  explicit StatisticsScene(IRenderSystem *input_render_system);
  ~StatisticsScene() override;

  void update_fields();

  void run() override;
};
