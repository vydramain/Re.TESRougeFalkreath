//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>

#include "entities/scenes_entities/IMainScene.h"
#include "systems/controls_systems/game_loop_controls/GLControlMap.h"
#include "systems/controls_systems/game_loop_controls/IGLControl.h"
#include "systems/location_systems/LocationSystem.h"
#include "systems/location_systems/sub_systems/entities_system/MagwehrsSystem.h"
#include "systems/render_systems/BearRenderSystem.h"

class GameLoopScene : public IMainScene {
 private:
  IRenderSystem *render_system;
  LocationSystem *location = nullptr;

 public:
  explicit GameLoopScene(IRenderSystem *input_system, unsigned input_x, unsigned input_y,
                         LocationsEntitiesSystem *input_entities);
  ~GameLoopScene() override;

  void run() override;
};
