//
// Created by vydra on 9/15/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectDown.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectEmpty.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectEnter.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectExit.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectLeft.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectRight.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/sub_controls/combat_controls/GLCControlSelectUp.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GLCControlMap {
 private:
  GLCControlSelectDown *control_down = nullptr;
  GLCControlSelectEmpty *control_empty = nullptr;
  GLCControlSelectEnter *control_enter = nullptr;
  GLCControlSelectExit *control_exit = nullptr;
  GLCControlSelectLeft *control_left = nullptr;
  GLCControlSelectRight *control_right = nullptr;
  GLCControlSelectUp *control_up = nullptr;

  std::map<int, IControl *> glcc_map;
  std::map<int, IControl *>::iterator glcc_iterator;

 public:
  explicit GLCControlMap(IWorldSystem *input_world_system, ParameterQueryDataSet *input_data) {
    PseudoLogSystem::log("GLCControlMap", "Creating game loop combat controls");
    control_down = new GLCControlSelectDown(input_world_system, input_data->get_data(new std::string("combat_data")));
    control_empty = new GLCControlSelectEmpty();
    control_enter = new GLCControlSelectEnter(input_world_system, input_data->get_data(new std::string("combat_data")));
    control_exit = new GLCControlSelectExit(input_world_system);
    control_left = new GLCControlSelectLeft(input_world_system);
    control_right = new GLCControlSelectRight(input_world_system);
    control_up = new GLCControlSelectUp(input_world_system, input_data->get_data(new std::string("combat_data")));

    glcc_map[TK_DOWN] = control_down;
    glcc_map[TK_ENTER] = control_enter;
    glcc_map[TK_ESCAPE] = control_exit;
    glcc_map[TK_LEFT] = control_left;
    glcc_map[TK_RIGHT] = control_right;
    glcc_map[TK_UP] = control_up;
  }

  ~GLCControlMap() {
    PseudoLogSystem::log("GLCControlMap", "Delete game loop combat controls");
    delete control_down;
    delete control_empty;
    delete control_enter;
    delete control_exit;
    delete control_left;
    delete control_right;
    delete control_up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    glcc_iterator = glcc_map.find(input_key);
    if (glcc_iterator == glcc_map.end()) {
      return control_empty;
    }
    return glcc_iterator->second;
  }
};