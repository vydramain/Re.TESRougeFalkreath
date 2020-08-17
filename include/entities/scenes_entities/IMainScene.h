//
// Created by vydra on 10.07.2020.
//

#pragma once

#include "entities/scenes_entities/IScene.h"

class IMainScene : public IScene {
 public:
  explicit IMainScene(const char *input_name = "MainScene") : IScene(input_name) {}
  ~IMainScene() override = default;

  void run() override = 0;
};
