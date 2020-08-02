//
// Created by vydra on 10.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_ISCENE_H_
#define INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_ISCENE_H_

#include <string>

#include "ecs/systems/controls_system/IControl.h"

class IScene {
 private:
  const char* name;

 public:
  explicit IScene(const char* input_name) : name(input_name) {}
  virtual ~IScene() = default;
  virtual void run() = 0;

  const char* getSceneName() const {
    return name;
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_ISCENE_H_
