//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLADVENTURE_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLADVENTURE_H_

#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/IMLControl.h"
#include "ecs/systems/scenes_system/main_loop_scene/AdventureScene.h"

class MLControlAdventure : public IMLControl {
 private:
  IControl *last_control = nullptr;
  AdventureScene *scene;

 public:
  explicit MLControlAdventure(Location *input_location)
      : IMLControl("MLControlAdventure"), scene(new AdventureScene(input_location)) {}
  ~MLControlAdventure() {
    delete scene;
  }

  IControl *get_last_control() {
    return last_control;
  }

  void execute() override {
    scene->run();
    last_control = scene->get_last_control();
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLADVENTURE_H_
