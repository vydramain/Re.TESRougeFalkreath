//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/controls/IGLControl.h"

class GLControlExit : public IGLControl {
 private:
 public:
  explicit GLControlExit() : IGLControl("GLControlExit") {}

  IControl *get_last_executed_control() override {
    return nullptr;
  }

  void execute() override {}
};
