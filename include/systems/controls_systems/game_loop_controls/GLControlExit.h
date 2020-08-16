//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/game_loop_controls/IGLControl.h"

class GLControlExit : public IGLControl {
 private:
 public:
  explicit GLControlExit() : IGLControl("GLControlExit") {}

  IControl *get_last_control() override {
    return nullptr;
  }

  void execute() override {}
};
