//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>

#include "entities/scenes_entities/IMainScene.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlMap.h"
#include "systems/render_systems/BearRenderSystem.h"

class GameLoopScene : public IMainScene {
 private:
  IRenderSystem *render_system;
  LocationSystem *location_system = nullptr;

  unsigned ending_count = 2;
  unsigned *ending_highlighted = new unsigned(1);

 public:
  explicit GameLoopScene(IRenderSystem *input_render_system);
  ~GameLoopScene() override;

  void run() override;
};
