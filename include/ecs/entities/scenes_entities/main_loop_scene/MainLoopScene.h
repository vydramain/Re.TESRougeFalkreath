//
// Created by vydra on 14.07.2020.
//

#pragma once

#include "ecs/entities/location_enity/Location.h"
#include "ecs/entities/scenes_entities/IMainScene.h"
#include "ecs/entities/scenes_entities/main_loop_scene/AdventureScene.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"
#include "ecs/systems/location_system/Creatures.h"
#include "ecs/systems/render_system/game_loop_render.h"

class MainLoopScene : public IMainScene {
 private:
  game_loop_render *render = nullptr;
  Location *location = nullptr;

 public:
  explicit MainLoopScene(const char *input_area_name = nullptr, Map *input_area = nullptr, Races *input_races = nullptr,
                         Creatures *input_creatures = nullptr, Items *input_items = nullptr);
  ~MainLoopScene() override;

  void run() override;
};
