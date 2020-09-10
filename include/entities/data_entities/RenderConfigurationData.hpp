//
// Created by vydra on 9/10/20.
//

#pragma once

#include "entities/location_entities/sentients_entities/Sentient.h"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class RenderConfigurationData {
 private:
  unsigned screen_mode_x = 0;
  unsigned screen_mode_y = 0;

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
  explicit RenderConfigurationData(unsigned int input_screen_x, unsigned int input_screen_y,
                                   IWorldSystem *input_world_system);
  ~RenderConfigurationData();

  void update_fields(unsigned input_screen_x, unsigned input_screen_y);
  void update_message_data();

  void set_location_system(IWorldSystem *input_world_system);
  void set_target(Sentient *input_target);
  void set_camera_position_x();
  void set_camera_position_y();

  void update_camera_position_x();
  void update_camera_position_y();

  unsigned get_screen_mode_x() const;
  unsigned get_screen_mode_y() const;

  unsigned get_passive_zone_out_x() const;
  unsigned get_passive_zone_out_y() const;
  unsigned get_active_zone_in_x() const;
  unsigned get_active_zone_in_y() const;
  unsigned get_active_zone_out_x() const;
  unsigned get_active_zone_out_y() const;

  unsigned get_text_size() const;
  unsigned get_message_right_in_x() const;
  unsigned get_message_left_out_x() const;

  const IWorldSystem *get_world_system() const;
  const Sentient *get_target() const;

  unsigned get_camera_position_x() const;
  unsigned get_camera_position_y() const;
};
