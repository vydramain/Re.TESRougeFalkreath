//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "systems/IControl.h"
#include "systems/scenes_systems/configuration_systems/controls/COControlSelectDown.h"
#include "systems/scenes_systems/configuration_systems/controls/COControlSelectEmpty.h"
#include "systems/scenes_systems/configuration_systems/controls/COControlSelectEnter.h"
#include "systems/scenes_systems/configuration_systems/controls/COControlSelectExit.h"
#include "systems/scenes_systems/configuration_systems/controls/COControlSelectUp.h"

class COControlMap {
 private:
  COControlSelectExit *exit = nullptr;
  COControlSelectEmpty *empty = nullptr;
  COControlSelectEnter *enter = nullptr;
  COControlSelectDown *down = nullptr;
  COControlSelectUp *up = nullptr;

  std::map<int, IControl *> c_map;
  std::map<int, IControl *>::iterator c_iterator;

 public:
  explicit COControlMap(IRenderSystem *input_render_system, ParameterQueryData *input_settings_data,
                        GameConfigurationData *input_global_configuration_data) {
    PseudoLogSystem::log("COControlMap", "Create configuration controls");
    down = new COControlSelectDown(input_settings_data);
    up = new COControlSelectUp(input_settings_data);
    exit = new COControlSelectExit();
    empty = new COControlSelectEmpty();
    enter = new COControlSelectEnter(input_render_system, input_settings_data, input_global_configuration_data);

    c_map.insert(std::make_pair(TK_CLOSE, exit));
    c_map.insert(std::make_pair(TK_ESCAPE, exit));
    c_map.insert(std::make_pair(TK_ENTER, enter));
    c_map.insert(std::make_pair(TK_UP, up));
    c_map.insert(std::make_pair(TK_DOWN, down));
  }

  ~COControlMap() {
    PseudoLogSystem::log("COControlMap", "Delete configuration controls");
    delete exit;
    delete empty;
    delete enter;
    delete down;
    delete up;
  }

  IControl *get_control(TERMINAL_API int input_key) {
    c_iterator = c_map.find(input_key);
    if (c_iterator == c_map.end()) {
      return empty;
    }
    return c_iterator->second;
  }
};
