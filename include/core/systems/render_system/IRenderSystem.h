//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/systems/location_system/ILocationSystem.h"

class IRenderSystem {
 public:
  virtual ~IRenderSystem() = default;

  virtual void set_pseudo_game_loop_render(ILocationSystem* input_location_system) = 0;
  virtual void set_main_menu_render(const char* input_question, const char** input_choices, unsigned input_count_choices,
                            unsigned* input_highlighted_choice) = 0;

  virtual void render() = 0;
};
