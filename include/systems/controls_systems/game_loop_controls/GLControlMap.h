//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "systems/controls_systems/game_loop_controls/GLControlAdventure.h"
#include "systems/controls_systems/game_loop_controls/GLControlEmpty.h"
#include "systems/controls_systems/game_loop_controls/GLControlExit.h"
#include "systems/location_systems/LocationSystem.h"

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
    printf("%s", "[GLControlMap] - Creating game loop controls\n");
    control_adventure = new GLControlAdventure(input_location);

    gl_map["GLAControlExit"] = control_exit;
  }

  ~GLControlMap() {
    printf("%s", "[GLControlMap] - Delete game loop controls\n");
    delete control_exit;
    delete control_empty;
    delete control_adventure;
  }

  IGLControl *get_start_control() {
    printf("%s", "[GLControlAdventure] - Launch adventure control at game loop\n");
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
