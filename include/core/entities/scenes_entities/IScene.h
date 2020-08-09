//
// Created by vydra on 10.07.2020.
//

#pragma once

#include "core/entities/Entity.h"
#include "core/systems/controls_system/IControl.h"

class IScene : public Entity {
 public:
  explicit IScene(const char* input_name) : Entity(input_name) {}
  ~IScene() override = default;
  virtual void run() = 0;
};
