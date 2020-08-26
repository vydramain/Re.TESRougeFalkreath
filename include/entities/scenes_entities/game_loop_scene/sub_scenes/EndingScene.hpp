//
// Created by vydra on 8/17/20.
//

#pragma once

#include "systems/controls_systems/scenes_controls/game_loop_controls/sub_controls/ending_controls/GLEControls.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

#include <cstring>

#include "entities/scenes_entities/IScene.h"

class EndingScene : public IScene {
 private:
  GLEControls *gle_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit EndingScene(LocationSystem *input_location, unsigned input_count, unsigned *input_highlighted);
  ~EndingScene() override;

  IControl *get_last_control();

  void run() override;
};