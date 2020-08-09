//
// Created by vydra on 14.07.2020.
//

#pragma once

#include <cstring>

#include "core/entities/scenes_entities/main_scenes/IMainScene.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/MLControlMap.h"
#include "ecs/systems/location_system/Creatures.h"
#include "ecs/systems/location_system/Location.h"
#include "ecs/systems/render_system/game_loop_render.h"

class MainLoopScene : public IMainScene {
 private:
  game_loop_render *render = nullptr;
  Location *location = nullptr;

 public:
  explicit MainLoopScene(const char *input_area_name = nullptr, Area *input_area = nullptr,
                         Races *input_races = nullptr, Creatures *input_creatures = nullptr,
                         Items *input_items = nullptr);
  ~MainLoopScene() override;

  void run() override;
};
