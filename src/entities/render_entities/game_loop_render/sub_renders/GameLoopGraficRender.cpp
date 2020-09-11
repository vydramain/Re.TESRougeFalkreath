//
// Created by vydra on 9/11/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopGraficRender.hpp"

GameLoopGraficRender::GameLoopGraficRender(RenderConfigurationData *input_data) {
  data = input_data;

  tiles_map["../sprites/tiny/ambients/glacier.png"] = 0xF000;
  tiles_map["../sprites/tiny/ambients/water.png"] = 0xF001;
  tiles_map["../sprites/tiny/ambients/wall.png"] = 0xF002;
  tiles_map["../sprites/tiny/ambients/tree.png"] = 0xF003;
  tiles_map["../sprites/tiny/ambients/throne.png"] = 0xF004;
  tiles_map["../sprites/tiny/ambients/roadbrick.png"] = 0xF005;
  tiles_map["../sprites/tiny/ambients/plant.png"] = 0xF006;
  tiles_map["../sprites/tiny/ambients/hedge.png"] = 0xF007;
  tiles_map["../sprites/tiny/ambients/hatch.png"] = 0xF008;
  tiles_map["../sprites/tiny/ambients/ground.png"] = 0xF009;
  tiles_map["../sprites/tiny/ambients/gate.png"] = 0xF00A;
  tiles_map["../sprites/tiny/ambients/cobblestone.png"] = 0xF00B;
  tiles_map["../sprites/tiny/ambients/cave_quit.png"] = 0xF00C;
  tiles_map["../sprites/tiny/ambients/door/door_c.png"] = 0xF00D;
  tiles_map["../sprites/tiny/ambients/door/door_o.png"] = 0xF00E;
  //  tiles_map["../"] = 0xF020;
  //  tiles_map["../"] = 0xF040;

  for (auto &it : tiles_map) {
    terminal_set(std::to_string(it.second).append(": ").append(it.first).data());
  }
}

void GameLoopGraficRender::render_ground() {
  terminal_layer(0);
  for (unsigned j = 0; j < data->get_passive_zone_out_y(); j++) {
    for (unsigned i = 0; i < data->get_passive_zone_out_x(); i++) {
      terminal_put(i, j, 0xF009);
    }
  }
}

void GameLoopGraficRender::render_ambient() {
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
      terminal_color(ambient->get_pseudo_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     ambient->get_pseudo_tile());
    }
  }
}

void GameLoopGraficRender::render_location_creatures() {
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
      terminal_color(sentient->get_pseudo_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     sentient->get_pseudo_tile());
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
      terminal_color(magwehr->get_pseudo_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     magwehr->get_pseudo_tile());
    }
  }
}

void GameLoopGraficRender::render_location_items() {
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
      terminal_color(item->get_pseudo_color());
      terminal_print(race_x - data->get_camera_position_x(), race_y - data->get_camera_position_y(),
                     item->get_pseudo_tile());
    }
  }
}

void GameLoopGraficRender::render() {
  render_ground();
  render_ambient();
  render_location_items();
  render_location_creatures();
}
