//
// Created by vydra on 9/10/20.
//

#include "entities/data_entities/RenderConfigurationData.hpp"

RenderConfigurationData::RenderConfigurationData(unsigned int input_screen_x, unsigned int input_screen_y,
                                                 IWorldSystem *input_world_system) {
  update_fields(input_screen_x, input_screen_y);
  set_location_system(input_world_system);
  set_target(input_world_system->get_current_map()->get_entities_system()->get_player());
  set_camera_position_x();
  set_camera_position_y();
  update_message_data();
}

RenderConfigurationData::~RenderConfigurationData() = default;

void RenderConfigurationData::update_fields(unsigned int input_screen_x, unsigned int input_screen_y) {
  screen_mode_x = input_screen_x;
  screen_mode_y = input_screen_y;
  passive_zone_out_x = input_screen_x - 34;
  passive_zone_out_y = input_screen_y;
  active_zone_in_x = passive_zone_out_x / 4;
  active_zone_in_y = passive_zone_out_y / 4;
  active_zone_out_x = passive_zone_out_x - active_zone_in_x;
  active_zone_out_y = passive_zone_out_y - active_zone_in_y;
}

void RenderConfigurationData::update_message_data() {
  if (passive_zone_out_x > 40) {
    text_size = passive_zone_out_x / 2 - 6;
  } else {
    text_size = passive_zone_out_x - 6;
  }
  if (passive_zone_out_x / 2 - 2 < text_size + 4) {
    message_right_in_x = 1;
  } else {
    message_right_in_x = passive_zone_out_x / 2 - 2;
  }
  if (passive_zone_out_x / 2 + 2 < text_size + 4) {
    message_left_out_x = text_size + 4;
  } else {
    message_left_out_x = passive_zone_out_x / 2 + 2;
  }
}

void RenderConfigurationData::set_location_system(IWorldSystem *input_world_system) {
  world_system = input_world_system;
}

void RenderConfigurationData::set_target(Sentient *input_target) {
  target = input_target;
}

void RenderConfigurationData::set_camera_position_x() {
  camera_position_x = target->get_current_x() - active_zone_in_x;
  if (target->get_current_x() < active_zone_in_x) {
    camera_position_x = 0;
  }
  if (world_system->get_current_map()->get_size_x() - target->get_current_x() < active_zone_out_x) {
    camera_position_x = world_system->get_current_map()->get_size_x() - passive_zone_out_x;
  }
}

void RenderConfigurationData::set_camera_position_y() {
  camera_position_y = target->get_current_y() - active_zone_in_y;
  if (target->get_current_y() < active_zone_in_y) {
    camera_position_y = 0;
  }
  if (world_system->get_current_map()->get_size_y() - target->get_current_y() < active_zone_out_y) {
    camera_position_y = world_system->get_current_map()->get_size_y() - passive_zone_out_y;
  }
}

void RenderConfigurationData::update_camera_position_x() {
  unsigned target_x = target->get_current_x();
  if (target_x < camera_position_x + active_zone_in_x || target_x > camera_position_x + active_zone_out_x) {
    if (target_x < camera_position_x + active_zone_in_x) {
      camera_position_x = target_x - active_zone_in_x;
      if (target_x < active_zone_in_x) {
        camera_position_x = 0;
      }
    }
    if (target_x > camera_position_x + active_zone_out_x) {
      camera_position_x = target_x - active_zone_out_x;
      if (target_x >= world_system->get_current_map()->get_size_x() - active_zone_in_x) {
        camera_position_x = world_system->get_current_map()->get_size_x() - passive_zone_out_x;
      }
    }
  }
}

void RenderConfigurationData::update_camera_position_y() {
  unsigned target_y = target->get_current_y();
  if (target_y < camera_position_y + active_zone_in_y || target_y > camera_position_y + active_zone_out_y) {
    if (target_y < camera_position_y + active_zone_in_y) {
      camera_position_y = target_y - active_zone_in_y;
      if (target_y < active_zone_in_y) {
        camera_position_y = 0;
      }
    }
    if (target_y > camera_position_y + active_zone_out_y) {
      camera_position_y = target_y - active_zone_out_y;
      if (target_y >= world_system->get_current_map()->get_size_y() - active_zone_in_y) {
        camera_position_y = world_system->get_current_map()->get_size_y() - passive_zone_out_y;
      }
    }
  }
}

unsigned RenderConfigurationData::get_screen_mode_x() const {
  return screen_mode_x;
}

unsigned RenderConfigurationData::get_screen_mode_y() const {
  return screen_mode_y;
}

unsigned RenderConfigurationData::get_passive_zone_out_x() const {
  return passive_zone_out_x;
}

unsigned RenderConfigurationData::get_passive_zone_out_y() const {
  return passive_zone_out_y;
}

unsigned RenderConfigurationData::get_active_zone_in_x() const {
  return active_zone_in_x;
}

unsigned RenderConfigurationData::get_active_zone_in_y() const {
  return active_zone_in_y;
}

unsigned RenderConfigurationData::get_active_zone_out_x() const {
  return active_zone_out_x;
}

unsigned RenderConfigurationData::get_active_zone_out_y() const {
  return active_zone_out_y;
}

unsigned RenderConfigurationData::get_text_size() const {
  return text_size;
}

unsigned RenderConfigurationData::get_message_right_in_x() const {
  return message_right_in_x;
}

unsigned RenderConfigurationData::get_message_left_out_x() const {
  return message_left_out_x;
}

const IWorldSystem *RenderConfigurationData::get_world_system() const {
  return world_system;
}

const Sentient *RenderConfigurationData::get_target() const {
  return target;
}

unsigned RenderConfigurationData::get_camera_position_x() const {
  return camera_position_x;
}

unsigned RenderConfigurationData::get_camera_position_y() const {
  return camera_position_y;
}
