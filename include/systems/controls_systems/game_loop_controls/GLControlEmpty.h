//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/game_loop_controls/IGLControl.h"

class GLControlEmpty : public IGLControl {
 public:
  explicit GLControlEmpty() : IGLControl("GLControlEmpty") {}

  IControl* get_last_control() override {
    return nullptr;
  }
  void execute() override {}
};
