//
// Created by vydra on 8/17/20.
//

#pragma once

#include <cstring>

#include "entities/scenes_entities/IScene.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/ending_controls/GLEControls.h"
#include "systems/location_systems/LocationSystem.h"

class EndingScene : public IScene {
 private:
  GLEControls *gle_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit EndingScene(LocationSystem *input_location, const unsigned input_count, unsigned *input_highlighted);
  ~EndingScene() override;

  IControl *get_last_control();

  void run() override;
};