//
// Created by vydra on 8/19/20.
//

#pragma once

#include <cstdio>

#include "entities/StringsListData.hpp"
#include "entities/scenes_entities/IMainScene.h"
#include "systems/controls_systems/scenes_controls/score_list_controls/SLControls.hpp"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/score_systems/IScoreSystem.hpp"
#include "systems/scenes_systems/score_systems/StdScoreSystem.hpp"

class ScoreListScene : public IMainScene {
 private:
  StringsListData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  SLControls *sl_input = nullptr;
  IControl *last_control = nullptr;

  IScoreSystem *score_system = nullptr;

 public:
  explicit ScoreListScene(IRenderSystem *input_render_system);
  ~ScoreListScene() override;

  void update_fields();

  void run() override;
};
