//
// Created by vydra on 8/24/20.
//

#pragma once

#include "IGLControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/IControl.h"
#include "systems_new/render_systems/IRenderSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/load/LoadSystem.h"

class GLControlLocationChange : public IGLControl {
 private:
  unsigned int x = 0;
  unsigned int y = 0;

  const char* locations_name = nullptr;
  const char* locations_file_name = nullptr;
  IWorldSystem* location_system = nullptr;
  IRenderSystem* render_system = nullptr;

 public:
  explicit GLControlLocationChange(IRenderSystem* input_render_system, IWorldSystem* input_world_system,
                                   const char* input_locations_name, const char* input_locations_file_name,
                                   unsigned int input_x, unsigned int input_y)
      : IGLControl("GLControlLocationChange") {
    x = input_x;
    y = input_y;

    locations_name = input_locations_name;
    locations_file_name = input_locations_file_name;
    location_system = input_world_system;
    render_system = input_render_system;
  }
  ~GLControlLocationChange() override {
    location_system = nullptr;
  }

  IControl* get_last_executed_control() override {
    return this;
  }

  void execute() override {}
};
