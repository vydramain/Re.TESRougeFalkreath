//
// Created by vydra on 7/30/20.
//

#pragma once

#include "ecs/entities/scenes_entities/IScene.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControls.h"
#include "ecs/systems/location_system/Location.h"

class AdventureScene : public IScene {
 private:
  Location *location;
  MLAControls *mla_input;
  IControl *last_control = nullptr;

 public:
  explicit AdventureScene(Location *input_location);
  ~AdventureScene() override;

  IControl *get_last_control();

  void run() override;
};
