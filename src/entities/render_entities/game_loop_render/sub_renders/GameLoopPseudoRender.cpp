//
// Created by vydra on 9/10/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopPseudoRender.hpp"

GameLoopPseudoRender::GameLoopPseudoRender(RenderConfigurationData *input_data) {
  data = input_data;
}

void GameLoopPseudoRender::render_ambient() {
  terminal_layer(1);
  const Ambient *ambient;
  for (unsigned i = 0; i < data->get_world_system()->get_current_map()->get_entities_system()->get_ambients_size();
       i++) {
    ambient = data->get_world_system()->get_current_map()->get_entities_system()->get_ambient(i);
    unsigned race_x = ambient->get_current_x();
    unsigned race_y = ambient->get_current_y();

    if ((race_x >= data->get_camera_position_x() &&
         race_x < data->get_camera_position_x() + data->get_passive_zone_out_x()) &&
        (race_y >= data->get_camera_position_y() &&
         race_y < data->get_camera_position_y() + data->get_passive_zone_out_y())) {
      terminal_color(ambient->get_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     ambient->get_tile());
    }
  }
}

void GameLoopPseudoRender::render_location_creatures() {
  terminal_layer(6);
  const Sentient *sentient;
  for (unsigned i = 0; i < data->get_world_system()->get_current_map()->get_entities_system()->get_sentients_size();
       i++) {
    sentient = data->get_world_system()->get_current_map()->get_entities_system()->get_sentient(i);
    unsigned race_x = sentient->get_current_x();
    unsigned race_y = sentient->get_current_y();

    if ((race_x >= data->get_camera_position_x() &&
         race_x < data->get_camera_position_x() + data->get_passive_zone_out_x()) &&
        (race_y >= data->get_camera_position_y() &&
         race_y < data->get_camera_position_y() + data->get_passive_zone_out_y())) {
      terminal_color(sentient->get_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     sentient->get_tile());
    }
  }

  const Magwehr *magwehr;
  for (unsigned i = 0; i < data->get_world_system()->get_current_map()->get_entities_system()->get_magwehrs_size();
       i++) {
    magwehr = data->get_world_system()->get_current_map()->get_entities_system()->get_magwehr(i);
    unsigned race_x = magwehr->get_current_x();
    unsigned race_y = magwehr->get_current_y();

    if ((race_x >= data->get_camera_position_x() &&
         race_x < data->get_camera_position_x() + data->get_passive_zone_out_x()) &&
        (race_y >= data->get_camera_position_y() &&
         race_y < data->get_camera_position_y() + data->get_passive_zone_out_y())) {
      terminal_color(magwehr->get_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     magwehr->get_tile());
    }
  }
}

void GameLoopPseudoRender::render_location_items() {
  terminal_layer(11);
  const Item *item;
  for (unsigned i = 0; i < data->get_world_system()->get_current_map()->get_entities_system()->get_items_size(); i++) {
    item = data->get_world_system()->get_current_map()->get_entities_system()->get_item(i);
    unsigned race_x = item->get_current_x();
    unsigned race_y = item->get_current_y();

    if ((race_x >= data->get_camera_position_x() &&
         race_x < data->get_camera_position_x() + data->get_passive_zone_out_x()) &&
        (race_y >= data->get_camera_position_y() &&
         race_y < data->get_camera_position_y() + data->get_passive_zone_out_y())) {
      terminal_layer(4);
      terminal_color(item->get_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(), item->get_tile());
    }
  }
}

void GameLoopPseudoRender::render() {
  render_ambient();
  render_location_creatures();
  render_location_items();
}
