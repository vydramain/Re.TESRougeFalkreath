//
// Created by vydra on 7/31/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLMAP_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLMAP_H_

#include <map>

#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/MLControlAdventure.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/MLControlEmpty.h"
#include "ecs/systems/controls_system/loop_controls/main_loop_scene_controls/MLControlExit.h"

class MLControlMap {
 private:
  MLControlExit *control_exit = new MLControlExit;
  MLControlEmpty *control_empty = new MLControlEmpty();
  MLControlAdventure *control_adventure;

  std::map<const char *, IMLControl *> ml_map;
  std::map<const char *, IMLControl *>::iterator ml_iterator;

  IMLControl *last_control = nullptr;

 public:
    explicit MLControlMap(Location *input_location) {
    control_adventure = new MLControlAdventure(input_location);

    ml_map["MLAControlExit"] = control_exit;
  }

  ~MLControlMap() {
    delete control_adventure;
  }

  IMLControl *get_start_control() {
    last_control = control_adventure;
    return control_adventure;
  }

  IMLControl *get_control(IControl *input_control) {
    ml_iterator = ml_map.find(input_control->get_name());
    if (ml_iterator == ml_map.end()) {
      return last_control;
    }
    last_control = ml_iterator->second;
    return ml_iterator->second;
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_SCENE_CONTROLS_MLCONTROLMAP_H_
