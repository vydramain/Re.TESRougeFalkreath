//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/ParameterQueryData.hpp"
#include "entities/StringsListData.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"

class IRenderSystem {
 public:
  virtual ~IRenderSystem() = default;

  virtual void set_main_menu_data(ParameterQueryData *input_menu_data) = 0;
  virtual void set_score_list_data(StringsListData *input_score_list_data) = 0;
  virtual void set_game_loop_data(ILocationSystem *input_location_system, ParameterQueryData *input_ending_data) = 0;

  virtual void set_main_menu_render() = 0;
  virtual void set_score_list_render() = 0;
  virtual void set_pseudo_game_loop_render() = 0;

  virtual void render() = 0;
};
