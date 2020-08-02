//
// Created by vydra on 14.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_MAINLOOPSCENE_H_
#define INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_MAINLOOPSCENE_H_

#include "ecs/entities/creatures_entities/Creatures.h"
#include "ecs/entities/locations_entities/Location.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"
#include "ecs/systems/render_system/game_loop_render.h"
#include "ecs/systems/scenes_system/IMainScene.h"
#include "ecs/systems/scenes_system/main_loop_scene/AdventureScene.h"

class MainLoopScene : public IMainScene {
 private:
  game_loop_render *render = nullptr;

  Location *location = nullptr;

 public:
  explicit MainLoopScene(const char *input_area_name = nullptr, Map *input_area = nullptr,
                         Creature *input_player = nullptr);
  ~MainLoopScene();

  void run() override;
};

#endif  // INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_MAINLOOPSCENE_H_
