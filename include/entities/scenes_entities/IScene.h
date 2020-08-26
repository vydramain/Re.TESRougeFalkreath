//
// Created by vydra on 10.07.2020.
//

#pragma once

#include "entities/Entity.h"

class IScene : public Entity {
 public:
  explicit IScene(const char* input_name = "IScene") : Entity(input_name) {}
  ~IScene() override = default;
  virtual void run() = 0;
};
