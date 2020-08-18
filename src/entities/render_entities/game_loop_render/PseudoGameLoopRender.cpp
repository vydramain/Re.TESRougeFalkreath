//
// Created by vydra on 8/12/20.
//

#include "entities/render_entities/game_loop_render/PseudoGameLoopRender.h"

void PseudoGameLoopRender::recount_fields(unsigned input_screen_x, unsigned input_screen_y) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;
  passive_zone_out_x = input_screen_x - 34;
  passive_zone_out_y = input_screen_y;
  active_zone_in_x = passive_zone_out_x / 4;
  active_zone_in_y = passive_zone_out_y / 4;
  active_zone_out_x = passive_zone_out_x - active_zone_in_x;
  active_zone_out_y = passive_zone_out_y - active_zone_in_y;
}

PseudoGameLoopRender::PseudoGameLoopRender(unsigned int input_screen_x, unsigned int input_screen_y,
                                           ILocationSystem *input_location_system, unsigned *input_highlighted)
    : IRender() {
  recount_fields(input_screen_x, input_screen_y);
  set_location_system(input_location_system);
  set_target(location_system->get_entities()->get_player());
  hud = new GameLoopHUDRender(input_location_system, target);
  hud->update_fields(SCREENMODE_X, SCREENMODE_Y, passive_zone_out_x, passive_zone_out_y, active_zone_in_x,
                     active_zone_in_y, active_zone_out_x, active_zone_out_y, camera_position_x, camera_position_y);
  ending = new GameLoopEndingRender(input_highlighted);
  ending->update_fields(SCREENMODE_X, SCREENMODE_Y);
}

PseudoGameLoopRender::~PseudoGameLoopRender() {
  location_system = nullptr;
  target = nullptr;
}

void PseudoGameLoopRender::set_location_system(ILocationSystem *input_location_system) {
  location_system = input_location_system;
}

void PseudoGameLoopRender::set_target(Sentient *input_target) {
  target = input_target;
  set_camera_position_x();
  set_camera_position_y();
}

void PseudoGameLoopRender::set_camera_position_x() {
  camera_position_x = target->get_current_x() - active_zone_in_x;
  if (target->get_current_x() < active_zone_in_x) {
    camera_position_x = 0;
  }
  if (location_system->get_size_x() - target->get_current_x() < active_zone_out_x) {
    camera_position_x = location_system->get_size_x() - passive_zone_out_x;
  }
}

void PseudoGameLoopRender::set_camera_position_y() {
  camera_position_y = target->get_current_y() - active_zone_in_y;
  if (target->get_current_y() < active_zone_in_y) {
    camera_position_y = 0;
  }
  if (location_system->get_size_y() - target->get_current_y() < active_zone_out_y) {
    camera_position_y = location_system->get_size_y() - passive_zone_out_y;
  }
}

void PseudoGameLoopRender::set_end() {
  is_end = true;
}

void PseudoGameLoopRender::update_camera_position_x() {
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
      if (target_x >= location_system->get_size_x() - active_zone_in_x) {
        camera_position_x = location_system->get_size_x() - passive_zone_out_x;
      }
    }
  }
}

void PseudoGameLoopRender::update_camera_position_y() {
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
      if (target_y >= location_system->get_size_y() - active_zone_in_y) {
        camera_position_y = location_system->get_size_y() - passive_zone_out_y;
      }
    }
  }
}

void PseudoGameLoopRender::render_ambient() {
  terminal_layer(1);
  const Ambient *ambient;
  for (unsigned i = 0; i < location_system->get_entities()->get_ambients_size(); i++) {
    ambient = location_system->get_entities()->get_ambient(i);
    unsigned race_x = ambient->get_current_x();
    unsigned race_y = ambient->get_current_y();

    if ((race_x >= camera_position_x && race_x < camera_position_x + passive_zone_out_x) &&
        (race_y >= camera_position_y && race_y < camera_position_y + passive_zone_out_y)) {
      terminal_color(ambient->get_color());
      terminal_print(race_x - camera_position_x, race_y - camera_position_y, ambient->get_tile());
    }
  }
}

void PseudoGameLoopRender::render_location_creatures() {
  terminal_layer(2);
  const Sentient *sentient;
  for (unsigned i = 0; i < location_system->get_entities()->get_sentients_size(); i++) {
    sentient = location_system->get_entities()->get_sentient(i);
    unsigned race_x = sentient->get_current_x();
    unsigned race_y = sentient->get_current_y();

    if ((race_x >= camera_position_x && race_x < camera_position_x + passive_zone_out_x) &&
        (race_y >= camera_position_y && race_y < camera_position_y + passive_zone_out_y)) {
      terminal_color(sentient->get_color());
      terminal_print(race_x - camera_position_x, race_y - camera_position_y, sentient->get_tile());
    }
  }

  const Magwehr *magwehr;
  for (unsigned i = 0; i < location_system->get_entities()->get_magwehrs_size(); i++) {
    magwehr = location_system->get_entities()->get_magwehr(i);
    unsigned race_x = magwehr->get_current_x();
    unsigned race_y = magwehr->get_current_y();

    if ((race_x >= camera_position_x && race_x < camera_position_x + passive_zone_out_x) &&
        (race_y >= camera_position_y && race_y < camera_position_y + passive_zone_out_y)) {
      terminal_color(magwehr->get_color());
      terminal_print(race_x - camera_position_x, race_y - camera_position_y, magwehr->get_tile());
    }
  }
}
void PseudoGameLoopRender::render_location_items() {
  const Item *item;
  for (unsigned i = 0; i < location_system->get_entities()->get_items_size(); i++) {
    item = location_system->get_entities()->get_item(i);
    unsigned race_x = item->get_current_x();
    unsigned race_y = item->get_current_y();

    if ((race_x >= camera_position_x && race_x < camera_position_x + passive_zone_out_x) &&
        (race_y >= camera_position_y && race_y < camera_position_y + passive_zone_out_y)) {
      terminal_layer(4);
      terminal_color(item->get_color());
      terminal_print(race_x - camera_position_x, race_y - camera_position_y, item->get_tile());
    }
  }
}

void PseudoGameLoopRender::render_hud() {
  hud->update_camera(camera_position_x, camera_position_y);
  hud->render();
}

void PseudoGameLoopRender::render_end() {
  ending->render();
}

void PseudoGameLoopRender::render() {
  CleanerRender::clean_all();

  update_camera_position_x();
  update_camera_position_y();

  if(!is_end) {
    render_ambient();
    render_location_items();
    render_location_creatures();
    render_hud();
  } else {
    render_end();
  }

  terminal_refresh();
}}
