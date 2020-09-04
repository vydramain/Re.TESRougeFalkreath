//
// Created by vydra on 7/30/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlEmpty.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlEnding.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlExit.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlPlayerDown.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlPlayerInteract.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlPlayerLeft.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlPlayerRight.h"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/adventure_controls/GLAControlPlayerUp.h"

class GLAControlMap {
 private:
  GLAControlEmpty *control_empty = nullptr;
  GLAControlEnding *control_ending = nullptr;
  GLAControlExit *control_exit = nullptr;
  GLAControlPlayerDown *control_player_down = nullptr;
  GLAControlPlayerLeft *control_player_left = nullptr;
  GLAControlPlayerRight *control_player_right = nullptr;
  GLAControlPlayerUp *control_player_up = nullptr;
  GLAControlPlayerInteract *control_player_interact = nullptr;

  std::map<int, IControl *> glas_map;
  std::map<int, IControl *>::iterator glas_iterator;

 public:
  explicit GLAControlMap(IWorldSystem *input_world_system) {
    PseudoLogSystem::log("GLAControlMap", "Creating game loop adventure controls");
    control_empty = new GLAControlEmpty();
    control_ending = new GLAControlEnding();
    control_exit = new GLAControlExit();
    control_player_down = new GLAControlPlayerDown(input_world_system);
    control_player_left = new GLAControlPlayerLeft(input_world_system);
    control_player_right = new GLAControlPlayerRight(input_world_system);
    control_player_up = new GLAControlPlayerUp(input_world_system);
    control_player_interact = new GLAControlPlayerInteract(input_world_system);

    glas_map[TK_ESCAPE] = control_exit;
    glas_map[TK_DOWN] = control_player_down;
    glas_map[TK_LEFT] = control_player_left;
    glas_map[TK_RIGHT] = control_player_right;
    glas_map[TK_UP] = control_player_up;
    glas_map[TK_E] = control_player_interact;

    glas_iterator = glas_map.begin();
  }

  ~GLAControlMap() {
    PseudoLogSystem::log("CLAControlMap", "Delete game loop adventure controls");
    delete control_empty;
    delete control_ending;
    delete control_exit;
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
