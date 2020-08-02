//
// Created by vydra on 7/30/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_ADVENTURESCENE_H_
#define INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_ADVENTURESCENE_H_

#include "ecs/entities/locations_entities/Location.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"
#include "ecs/systems/scenes_system/IScene.h"

class AdventureScene : public IScene {
 private:
  Location *location;
  MLAControls *mla_input;
  IControl *last_control = nullptr;

 public:
  explicit AdventureScene(Location *input_location)
      : IScene("AdventureScene"), location(input_location), mla_input(new MLAControls(input_location)) {}

  ~AdventureScene() {
    location = nullptr;
    delete mla_input;
  }

  IControl *get_last_control() {
    return last_control;
  }

  void run();
};

#endif  // INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_MAIN_LOOP_SCENE_ADVENTURESCENE_H_
