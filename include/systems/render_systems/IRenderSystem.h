//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/scenes_entities/score_list_scene/scenes_data/ScoreListData.hpp"
#include "systems/location_systems/ILocationSystem.h"

class IRenderSystem {
 public:
  virtual ~IRenderSystem() = default;

  virtual void set_main_menu_data(const char *input_menu_title, const char **input_menu_choices,
                                  unsigned input_count_menu_choices, unsigned *input_menu_highlighted) = 0;
  virtual void set_score_list_data(ScoreListData *input_score_list_data) = 0;
  virtual void set_game_loop_data(ILocationSystem *input_location_system, unsigned *input_highlighted) = 0;

  virtual void set_main_menu_render() = 0;
  virtual void set_score_list_render() = 0;
  virtual void set_pseudo_game_loop_render() = 0;

  virtual void render() = 0;
};
