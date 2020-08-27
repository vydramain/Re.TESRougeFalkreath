//
// Created by vydra on 8/12/20.
//

#pragma once

#include <cstring>

#include "./BearLibTerminal.h"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "entities/render_entities/game_loop_render/sub_renders/GameLoopEndingRender.hpp"
#include "entities/render_entities/game_loop_render/sub_renders/GameLoopHUDRender.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/SentientsSystem.h"

class PseudoGameLoopRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  unsigned passive_zone_out_x = 0;
  unsigned passive_zone_out_y = 0;
  unsigned active_zone_in_x = 0;
  unsigned active_zone_in_y = 0;
  unsigned active_zone_out_x = 0;
  unsigned active_zone_out_y = 0;

  ILocationSystem *location_system = nullptr;
  const Sentient *target = nullptr;

  unsigned camera_position_x = 0;
  unsigned camera_position_y = 0;

  GameLoopHUDRender *hud = nullptr;
  GameLoopEndingRender *ending = nullptr;

  void recount_fields(unsigned input_screen_x, unsigned input_screen_y);

 public:
  explicit PseudoGameLoopRender(unsigned input_screen_x, unsigned input_screen_y,
                                ILocationSystem *input_location_system, ParameterQueryData *input_ending_data);
  ~PseudoGameLoopRender() override;

  void set_location_system(ILocationSystem *input_location_system);
  void set_target(Sentient *input_target);
  void set_camera_position_x();
  void set_camera_position_y();

  void update_camera_position_x();
  void update_camera_position_y();

  void render_ambient();
  void render_location_creatures();
  void render_location_items();

  void render_hud();
  void render_end();

  void render() override;
};
