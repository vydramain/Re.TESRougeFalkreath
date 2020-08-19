//
// Created by vydra on 8/19/20.
//

#pragma once

#include <cstdio>

#include "entities/scenes_entities/score_list_scene/ScoreListScene.hpp"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"

class GControlScoreList : public IControl {
 private:
  IRenderSystem *render_system = nullptr;
  unsigned *highlighted;

 public:
  explicit GControlScoreList(IRenderSystem *input_render_system, unsigned *input_pointer)
      : IControl("GControlScoreList"), render_system(input_render_system), highlighted(input_pointer) {}
  ~GControlScoreList() override = default;

  void execute() override {
    printf("[GControlScoreList] - execute score list control");
    *highlighted = 0;
    auto *scene = new ScoreListScene(render_system);
    scene->run();
    delete scene;
  }
};