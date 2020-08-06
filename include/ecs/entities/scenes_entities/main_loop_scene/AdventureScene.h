//
// Created by vydra on 7/30/20.
//

#pragma once

#include "ecs/entities/location_enity/Location.h"
#include "ecs/entities/scenes_entities/IScene.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"

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
