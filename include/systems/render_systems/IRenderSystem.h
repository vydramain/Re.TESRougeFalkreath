//
// Created by vydra on 8/14/20.
//

#pragma once

#include <string>

#include "entities/render_entities/data/StringsListData.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"
#include "systems/launcher_system/data/ParameterQueryDataSet.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class IRenderSystem {
 public:
  virtual ~IRenderSystem() = default;

  virtual void reset_render() = 0;
  virtual void set_resolution_1280x720() = 0;
  virtual void set_resolution_1920x1080() = 0;
  virtual void set_pseudo_mode() = 0;
  virtual void set_grafic_mode() = 0;

  virtual void set_main_menu_data(ParameterQueryData *input_menu_data) = 0;
  virtual void set_score_list_data(StringsListData *input_score_list_data) = 0;
  virtual void set_settings_data(ParameterQueryData *input_settings_data) = 0;
  virtual void set_game_loop_data(IWorldSystem *input_world_system, ParameterQueryDataSet *input_ending_data) = 0;

  virtual void set_main_menu_render() = 0;
  virtual void set_score_list_render() = 0;
  virtual void set_setting_render() = 0;
  virtual void set_pseudo_game_loop_render() = 0;

  virtual void render() = 0;
};
