//
// Created by vydra on 7/30/20.
//

#pragma once

#include <BearLibTerminal.h>

#include <map>

#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlEmpty.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlExit.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlPlayerDown.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlPlayerInteract.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlPlayerLeft.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlPlayerRight.h"
#include "systems/controls_systems/game_loop_controls/sub_controls/adventure_controls/GLAControlPlayerUp.h"

class GLAControlMap {
 private:
  GLAControlExit *control_exit = nullptr;
  GLAControlEmpty *control_empty = nullptr;
  GLAControlPlayerDown *control_player_down = nullptr;
  GLAControlPlayerLeft *control_player_left = nullptr;
  GLAControlPlayerRight *control_player_right = nullptr;
  GLAControlPlayerUp *control_player_up = nullptr;
  GLAControlPlayerInteract *control_player_interact = nullptr;

  std::map<int, IControl *> glas_map;
  std::map<int, IControl *>::iterator glas_iterator;

 public:
  explicit GLAControlMap(LocationSystem *input_location) {
    printf("%s", "[GLAControlMap] - Creating game loop adventure controls\n");
    control_exit = new GLAControlExit();
    control_empty = new GLAControlEmpty();
    control_player_down = new GLAControlPlayerDown(input_location);
    control_player_left = new GLAControlPlayerLeft(input_location);
    control_player_right = new GLAControlPlayerRight(input_location);
    control_player_up = new GLAControlPlayerUp(input_location);
    control_player_interact = new GLAControlPlayerInteract(input_location);

    glas_map[TK_ESCAPE] = control_exit;
    glas_map[TK_DOWN] = control_player_down;
    glas_map[TK_LEFT] = control_player_left;
    glas_map[TK_RIGHT] = control_player_right;
    glas_map[TK_UP] = control_player_up;
    glas_map[TK_E] = control_player_interact;

    glas_iterator = glas_map.begin();
  }

  ~GLAControlMap() {
    printf("%s", "[CLAControlMap] - Delete game loop adventure controls\n");
    delete control_exit;
    delete control_empty;
    delete control_player_down;
    delete control_player_left;
    delete control_player_right;
    delete control_player_up;
    delete control_player_interact;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    glas_iterator = glas_map.find(input_key);
    if (glas_iterator == glas_map.end()) {
      return control_empty;
    }
    return glas_iterator->second;
  }
};