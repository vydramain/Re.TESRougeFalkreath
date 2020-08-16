//
// Created by vydra on 8/12/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "systems/location_systems/LocationSystem.h"
#include "systems/location_systems/sub_systems/entities_system/SentientsSystem.h"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"

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

  const ILocationSystem *location_system = nullptr;
  const Sentient *target = nullptr;

  unsigned camera_position_x = 0;
  unsigned camera_position_y = 0;

  void recount_fields(unsigned input_screen_x, unsigned input_screen_y);

 public:
  explicit PseudoGameLoopRender(unsigned input_screen_x, unsigned input_screen_y,
                                ILocationSystem *input_location_system);
  ~PseudoGameLoopRender() override;

  void set_location_system(ILocationSystem *input_location_system);
  void set_target(Sentient *input_target);
  void set_camera_position_x();
  void set_camera_position_y();

  void update_camera_position_x();
  void update_camera_position_y();

  void check_interact();

  void render_ambient();
  void render_location_creatures();
  void render_location_items();
  void render_hud();

  void render() override;
};
