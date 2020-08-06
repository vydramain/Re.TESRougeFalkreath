//
// Created by vydra on 10.07.2020.
//

#pragma once

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