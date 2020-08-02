//
// Created by vydra on 10.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_IMAINSCENE_H_
#define INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_IMAINSCENE_H_

#include <string>

#include "./IScene.h"

class IMainScene : public IScene {
 public:
  explicit IMainScene(const char *input_name = "MainScene") : IScene(input_name) {}

  void run() override = 0;
};

#endif  // INCLUDE_ECS_SYSTEMS_SCENES_SYSTEM_IMAINSCENE_H_
