//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlAdventure.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlEmpty.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlEnding.hpp"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlExit.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlScoreSave.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLControlMap {
 private:
  GLControlAdventure *control_adventure = nullptr;
  GLControlExit *control_exit = nullptr;
  GLControlEmpty *control_empty = nullptr;
  GLControlEnding *control_ending = nullptr;
  GLControlScoreSave *control_score = nullptr;

  std::map<const char *, IGLControl *> gl_map;
  std::map<const char *, IGLControl *>::iterator gl_iterator;

  ILocationSystem *location_system = nullptr;
  IGLControl *last_control = nullptr;

 public:
  explicit GLControlMap(LocationSystem *input_location_system, const unsigned input_count,
                        unsigned *input_highlighted) {
    printf("%s", "[GLControlMap] - Creating game loop controls\n");
    control_adventure = new GLControlAdventure(input_location_system);
    control_empty = new GLControlEmpty();
    control_ending = new GLControlEnding(input_location_system, input_count, input_highlighted);
    control_exit = new GLControlExit();
    control_score = new GLControlScoreSave(input_location_system, input_count, input_highlighted);

    gl_map["GLAControlExit"] = control_exit;
    gl_map["GLAControlEnding"] = control_ending;
    gl_map["GLEControlSelectEnter"] = control_score;
    gl_map["GLEControlSelectExit"] = control_exit;

    location_system = input_location_system;
  }

  ~GLControlMap() {
    printf("%s", "[GLControlMap] - Delete game loop controls\n");
    delete control_adventure;
    delete control_empty;
    delete control_ending;
    delete control_exit;
    delete control_score;
  }

  IGLControl *get_start_control() {
    printf("%s", "[GLControlMap] - Launch adventure control at game loop\n");
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
    if (location_system->is_story_over()) {
      return control_ending;
    }
    return last_control;
  }
};
