//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "core/systems/controls_system/game_loop_controls/GLControlAdventure.h"
#include "core/systems/controls_system/game_loop_controls/GLControlEmpty.h"
#include "core/systems/controls_system/game_loop_controls/GLControlExit.h"
#include "ecs/systems/location_system/LocationSystem.h"

class GLControlMap {
 private:
  GLControlExit *control_exit = new GLControlExit;
  GLControlEmpty *control_empty = new GLControlEmpty();
  GLControlAdventure *control_adventure = nullptr;

  std::map<const char *, IGLControl *> gl_map;
  std::map<const char *, IGLControl *>::iterator gl_iterator;

  IGLControl *last_control = nullptr;

 public:
  explicit GLControlMap(LocationSystem *input_location) {
    control_adventure = new GLControlAdventure(input_location);

    gl_map["GLAControlExit"] = control_exit;
  }

  ~GLControlMap() {
    delete control_exit;
    delete control_empty;
    delete control_adventure;
  }

  IGLControl *get_start_control() {
    last_control = control_adventure;
    return control_adventure;
  }

  IGLControl *get_control(IControl *input_control) {
    for (gl_iterator = gl_map.begin(); gl_iterator != gl_map.end(); gl_iterator++) {
      if (std::strcmp(gl_iterator->first, input_control->get_name()) == 0) {
        last_control = gl_iterator->second;
        return gl_iterator->second;
      }
    }
    return last_control;
  }
};
