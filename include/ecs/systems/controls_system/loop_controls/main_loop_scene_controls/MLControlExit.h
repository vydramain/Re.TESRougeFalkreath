//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLEXIT_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLEXIT_H_

#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/IMLControl.h"

class MLControlExit : public IMLControl {
 private:
 public:
  explicit MLControlExit() : IMLControl("MLControlExit") {}

  IControl *get_last_control() override {
    return nullptr;
  }

  void execute() override {}
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLEXIT_H_
