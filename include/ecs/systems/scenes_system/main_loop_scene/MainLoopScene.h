//
// Created by vydra on 14.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_MAINLOOPSCENE_H_
#define INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_MAINLOOPSCENE_H_

#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"
#include "ecs/systems/location_system/Creatures.h"
#include "ecs/systems/location_system/Location.h"
#include "ecs/systems/render_system/game_loop_render.h"
#include "ecs/systems/scenes_system/IMainScene.h"
#include "ecs/systems/scenes_system/main_loop_scene/AdventureScene.h"

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

#endif  // INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_MAINLOOPSCENE_H_
