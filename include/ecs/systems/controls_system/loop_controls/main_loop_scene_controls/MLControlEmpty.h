//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLEMPTY_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLEMPTY_H_

#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/IMLControl.h"

class MLControlEmpty : public IMLControl {
 public:
  explicit MLControlEmpty() : IMLControl("MLControlEmpty") {}

  IControl* get_last_control() {
    return nullptr;
  }
  void execute() {}
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLEMPTY_H_
