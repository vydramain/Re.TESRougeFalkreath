//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_IMLCONTROL_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_IMLCONTROL_H_

#include "ecs/systems/controls_system/IControl.h"

class IMLControl : public IControl {
 public:
  explicit IMLControl(const char* input_name = "IMLControl") : IControl(input_name) {}

  virtual IControl* get_last_control() = 0;
  void execute() override = 0;
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_IMLCONTROL_H_
