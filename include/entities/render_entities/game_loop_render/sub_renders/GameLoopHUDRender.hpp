//
// Created by vydra on 8/17/20.
//

#pragma once

#include <cstring>

#include "./BearLibTerminal.h"
#include "entities/location_entities/sentients_entities/Sentient.h"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GameLoopHUDRender : public IRender {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  unsigned passive_zone_out_x = 0;
  unsigned passive_zone_out_y = 0;
  unsigned active_zone_in_x = 0;
  unsigned active_zone_in_y = 0;
  unsigned active_zone_out_x = 0;
  unsigned active_zone_out_y = 0;

  unsigned text_size = 0;
  unsigned message_right_in_x = 0;
  unsigned message_left_out_x = 0;

  const IWorldSystem *world_system = nullptr;
  const Sentient *target = nullptr;

  unsigned camera_position_x = 0;
  unsigned camera_position_y = 0;

 public:
  explicit GameLoopHUDRender(IWorldSystem *input_world_system, const Sentient *input_target);
  ~GameLoopHUDRender() override;

  void update_fields(unsigned input_screen_x, unsigned input_screen_y, unsigned input_passive_zone_out_x,
                     unsigned input_passive_zone_out_y, unsigned input_active_zone_in_x,
                     unsigned input_active_zone_in_y, unsigned input_active_zone_out_x,
                     unsigned input_active_zone_out_y, unsigned input_camera_position_x,
                     unsigned input_camera_position_y);
  void update_camera(unsigned input_camera_position_x, unsigned input_camera_position_y);
  void update_message_data();

  std::vector<std::string *> *prepare_string_message(std::string *input_text) const;
  void view_string_message(std::vector<std::string *> *input_text);
  void produce_string_message(std::string *input_text);

  void check_item_interact(unsigned input_index);
  void check_ambient_interact(unsigned input_index);

  void render_borders();
  void render_nameplate();
  void render_inventory();
  void render_coordinates();
  void render_interact_ability();

  void render() override;
};