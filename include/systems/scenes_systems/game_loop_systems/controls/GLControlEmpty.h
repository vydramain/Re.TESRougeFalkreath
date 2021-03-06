//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/controls/IGLControl.h"

class GLControlEmpty : public IGLControl {
 public:
  explicit GLControlEmpty() : IGLControl("GLControlEmpty") {}

  IControl* get_last_executed_control() override {
    return nullptr;
  }
  void execute() override {}
};
