//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>

#include "core/entities/scenes_entities/IMainScene.h"
#include "core/systems/controls_system/game_loop_controls/GLControlMap.h"
#include "core/systems/controls_system/game_loop_controls/IGLControl.h"
#include "core/systems/location_system/LocationSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "core/systems/render_system/RenderSystem.h"
#include "ecs/systems/render_system/game_loop_render.h"

class GameLoopScene : public IMainScene {
 private:
  RenderSystem *render_system;
  LocationSystem *location = nullptr;

 public:
  explicit GameLoopScene(RenderSystem *input_system, const char *input_area_name, Area *input_area,
                         LocationsEntitiesSystem *input_entities);
  ~GameLoopScene() override;

  void run() override;
};
