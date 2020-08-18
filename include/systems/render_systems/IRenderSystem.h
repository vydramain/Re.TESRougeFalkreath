//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/location_systems/ILocationSystem.h"

class IRenderSystem {
 public:
  virtual ~IRenderSystem() = default;

  virtual void set_pseudo_game_loop_render() = 0;
  virtual void set_main_menu_render() = 0;

  virtual void render() = 0;
};
