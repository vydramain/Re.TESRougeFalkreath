//
// Created by vydra on 8/16/20.
//

#pragma once

#include "entities/scenes_entities/IScene.h"
#include "systems/location_systems/LocationSystem.h"

class EndingScene : public IScene {
 private:
  LocationSystem *location = nullptr;

 public:
  explicit EndingScene(LocationSystem *input_location);
  ~EndingScene() override;

  void run() override;
};
