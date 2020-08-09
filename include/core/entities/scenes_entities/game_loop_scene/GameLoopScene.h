//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>

#include "core/systems/controls_system/game_loop_controls/IGLControl.h"
#include "core/systems/controls_system/game_loop_controls/GLControlMap.h"
#include "core/entities/scenes_entities/IMainScene.h"
#include "ecs/systems/location_system/Creatures.h"
#include "ecs/systems/location_system/Location.h"
#include "ecs/systems/render_system/game_loop_render.h"

class GameLoopScene : public IMainScene {
 private:
  game_loop_render *render = nullptr;
  Location *location = nullptr;

 public:
  explicit GameLoopScene(const char *input_area_name = nullptr, Area *input_area = nullptr,
                         Races *input_races = nullptr, Creatures *input_creatures = nullptr,
                         Items *input_items = nullptr);
  ~GameLoopScene() override;

  void run() override;
};
