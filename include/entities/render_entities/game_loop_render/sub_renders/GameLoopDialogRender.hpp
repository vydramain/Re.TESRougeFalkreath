//
// Created by vydra on 8/18/20.
//

#pragma once

#include "entities/location_entities/sentients_entities/Sentient.h"
#include "entities/render_entities/IRender.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GameLoopDialogRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  unsigned passive_zone_out_x = 0;
  unsigned passive_zone_out_y = 0;
  unsigned active_zone_in_x = 0;
  unsigned active_zone_in_y = 0;
  unsigned active_zone_out_x = 0;
  unsigned active_zone_out_y = 0;

  const IWorldSystem *world_system = nullptr;
  const Sentient *target = nullptr;

  unsigned camera_position_x = 0;
  unsigned camera_position_y = 0;

  const char *first_dialog_string = nullptr;
  const char *second_dialog_string = nullptr;

  const char *question = nullptr;
  const char **choices = nullptr;
  unsigned count_choices = 0;
  unsigned *highlighted = nullptr;

 public:
  explicit GameLoopDialogRender(IWorldSystem *input_system, const Sentient *input_target);
  ~GameLoopDialogRender() override;

  void update_fields(unsigned input_screen_x, unsigned input_screen_y, unsigned input_passive_zone_out_x,
                     unsigned input_passive_zone_out_y, unsigned input_active_zone_in_x,
                     unsigned input_active_zone_in_y, unsigned input_active_zone_out_x,
                     unsigned input_active_zone_out_y, unsigned input_camera_position_x,
                     unsigned input_camera_position_y);
  void update_camera(unsigned input_camera_position_x, unsigned input_camera_position_y);

  void set_dialog(const char *input_first_string, const char *input_second_string);
  void set_question(const char *input_question, const char **input_choices, unsigned input_count_choices,
                    unsigned *input_highlighted);

  void render_dialog();
  void render_question();

  void render() override;
};