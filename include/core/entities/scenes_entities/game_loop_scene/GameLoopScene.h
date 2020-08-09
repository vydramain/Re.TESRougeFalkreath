//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>

#include "core/entities/scenes_entities/IMainScene.h"
#include "core/systems/controls_system/game_loop_controls/GLControlMap.h"
#include "core/systems/controls_system/game_loop_controls/IGLControl.h"
#include "ecs/systems/location_system/LocationSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "ecs/systems/render_system/game_loop_render.h"

class GameLoopScene : public IMainScene {
 private:
  game_loop_render *render = nullptr;
  LocationSystem *location = nullptr;

 public:
  explicit GameLoopScene(const char *input_area_name = nullptr, Area *input_area = nullptr,
                         SentientsSystem *input_races = nullptr, MagwehrsSystem *input_creatures = nullptr,
                         ItemsSystem *input_items = nullptr);
  ~GameLoopScene() override;

  void run() override;
};
