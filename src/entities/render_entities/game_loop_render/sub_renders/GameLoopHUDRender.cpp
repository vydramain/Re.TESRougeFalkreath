//
// Created by vydra on 8/17/20.
//

#include <entities/render_entities/game_loop_render/sub_renders/GameLoopHUDRender.hpp>

GameLoopHUDRender::GameLoopHUDRender(ILocationSystem *input_system, const Sentient *input_target)
    : location_system(input_system), target(input_target) {}

GameLoopHUDRender::~GameLoopHUDRender() {
  location_system = nullptr;
  target = nullptr;
}

void GameLoopHUDRender::update_fields(unsigned int input_screen_x, unsigned int input_screen_y,
                                      unsigned int input_passive_zone_out_x, unsigned int input_passive_zone_out_y,
                                      unsigned int input_active_zone_in_x, unsigned int input_active_zone_in_y,
                                      unsigned int input_active_zone_out_x, unsigned int input_active_zone_out_y,
                                      unsigned int input_camera_position_x, unsigned int input_camera_position_y) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  passive_zone_out_x = input_passive_zone_out_x;
  passive_zone_out_y = input_passive_zone_out_y;
  active_zone_in_x = input_active_zone_in_x;
  active_zone_in_y = input_active_zone_in_y;
  active_zone_out_x = input_active_zone_out_x;
  active_zone_out_y = input_active_zone_out_y;

  camera_position_x = input_camera_position_x;
  camera_position_y = input_camera_position_y;
}

void GameLoopHUDRender::update_camera(unsigned int input_camera_position_x, unsigned int input_camera_position_y) {
  camera_position_x = input_camera_position_x;
  camera_position_y = input_camera_position_y;
}

void GameLoopHUDRender::check_item_interact(unsigned input_index) {
  terminal_color(0xffffffff);

  if (camera_position_x + (passive_zone_out_x / 2) < target->get_current_x()) {
    CleanerRender::clean_area(1, passive_zone_out_y - 6, passive_zone_out_x / 2 + 2, passive_zone_out_y - 1);
    TextPanelsRender::view_text(1, passive_zone_out_y - 6, passive_zone_out_x / 2 + 1, passive_zone_out_y - 2,
                                "Нажмите 'E' для взаимодействия", "");
  } else {
    CleanerRender::clean_area((passive_zone_out_x / 2) - 2, passive_zone_out_y - 6, passive_zone_out_x - 1,
                              passive_zone_out_y - 1);
    TextPanelsRender::view_text((passive_zone_out_x / 2) - 2, passive_zone_out_y - 6, passive_zone_out_x - 2,
                                passive_zone_out_y - 2, "Нажмите 'E' для взаимодействия", "");
  }
}

void GameLoopHUDRender::check_ambient_interact(unsigned input_index) {
  terminal_color(0xffffffff);
  if (std::strcmp(location_system->get_entities()->get_ambient(input_index)->get_name(), "Door") == 0) {
    if (location_system->get_entities()->get_ambient(input_index)->get_floor()) {
      if (camera_position_x + (passive_zone_out_x / 2) < target->get_current_x()) {
        CleanerRender::clean_area(1, passive_zone_out_y - 6, passive_zone_out_x / 2 + 2, passive_zone_out_y - 1);
        TextPanelsRender::view_text(1, passive_zone_out_y - 6, passive_zone_out_x / 2 + 1, passive_zone_out_y - 2,
                                    "Нажмите 'E' чтобы закрыть", "");
      } else {
        CleanerRender::clean_area((passive_zone_out_x / 2) - 1, passive_zone_out_y - 6, passive_zone_out_x - 1,
                                  passive_zone_out_y - 1);
        TextPanelsRender::view_text((passive_zone_out_x / 2) - 1, passive_zone_out_y - 6, passive_zone_out_x - 2,
                                    passive_zone_out_y - 2, "Нажмите 'E' чтобы закрыть", "");
      }
    } else {
      if (camera_position_x + (passive_zone_out_x / 2) < target->get_current_x()) {
        CleanerRender::clean_area(1, passive_zone_out_y - 6, passive_zone_out_x / 2 + 2, passive_zone_out_y - 1);
        TextPanelsRender::view_text(1, passive_zone_out_y - 6, passive_zone_out_x / 2 + 1, passive_zone_out_y - 2,
                                    "Нажмите 'E' чтобы открыть", "");
      } else {
        CleanerRender::clean_area((passive_zone_out_x / 2) - 1, passive_zone_out_y - 6, passive_zone_out_x - 1,
                                  passive_zone_out_y - 1);
        TextPanelsRender::view_text((passive_zone_out_x / 2) - 1, passive_zone_out_y - 6, passive_zone_out_x - 2,
                                    passive_zone_out_y - 2, "Нажмите 'E' чтобы открыть", "");
      }
    }
  }

  if (std::strcmp(location_system->get_entities()->get_ambient(input_index)->get_name(), "SouthGate") == 0) {
    if (camera_position_x + (passive_zone_out_x / 2) < target->get_current_x()) {
      CleanerRender::clean_area(1, passive_zone_out_y - 7, passive_zone_out_x / 2 + 2, passive_zone_out_y - 1);
      TextPanelsRender::view_text(1, passive_zone_out_y - 7, passive_zone_out_x / 2 + 1, passive_zone_out_y - 2,
                                  "Нажмите 'E' чтобы отправиться", "в дальние земли");
    } else {
      CleanerRender::clean_area((passive_zone_out_x / 2) - 1, passive_zone_out_y - 7, passive_zone_out_x - 1,
                                passive_zone_out_y - 1);
      TextPanelsRender::view_text((passive_zone_out_x / 2) - 1, passive_zone_out_y - 7, passive_zone_out_x - 2,
                                  passive_zone_out_y - 2, "Нажмите 'E' чтобы отправиться", "в дальние земли");
    }
  }
}

void GameLoopHUDRender::render_borders() {
  terminal_layer(10);
  terminal_color(0xffffffff);
  for (unsigned i = 0; i < passive_zone_out_y; i++) {
    terminal_print(passive_zone_out_x, i, "│");
  }

  terminal_print(passive_zone_out_x, 9, "├");
  terminal_print(passive_zone_out_x, passive_zone_out_y - 5, "├");
  for (unsigned i = 0; i < SCREENMODE_X - passive_zone_out_x; i++) {
    terminal_print(passive_zone_out_x + i + 1, 9, "─");
    terminal_print(passive_zone_out_x + i + 1, passive_zone_out_y - 5, "─");
  }
}

void GameLoopHUDRender::render_nameplate() {
  terminal_color(0xffffffff);
  terminal_print(passive_zone_out_x + 1, 1, "Имя:");
  terminal_print(passive_zone_out_x + 1, 2, "Раса:");
  terminal_print(passive_zone_out_x + 1, 3, "Статус:");

  terminal_color(0xFFFF4444);
  terminal_print(passive_zone_out_x + 1, 4, "ОЗ:");
  terminal_color(0xFF44ff44);
  terminal_print(passive_zone_out_x + 1, 5, "ОД:");
  terminal_color(0xFF6666FF);
  terminal_print(passive_zone_out_x + 1, 6, "OМ:");
}

void GameLoopHUDRender::render_inventory() {
  terminal_color(0xffffffff);
  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 6, "Кошель:");
  char wallet[7];
  snprintf(wallet, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_wallet());
  terminal_print(passive_zone_out_x + 9, passive_zone_out_y - 6, wallet);
}

void GameLoopHUDRender::render_coordinates() {
  terminal_color(0xffffffff);
  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 3, "Координаты:");
  char x[4], y[4];
  snprintf(x, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_current_x());
  snprintf(y, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_current_y());
  terminal_print(passive_zone_out_x + 15, passive_zone_out_y - 3, x);
  terminal_print(passive_zone_out_x + 18, passive_zone_out_y - 3, y);
}

void GameLoopHUDRender::render_interact_ability() {
  terminal_color(0xffffffff);
  unsigned new_x = location_system->get_entities()->get_player()->get_sight_x();
  unsigned new_y = location_system->get_entities()->get_player()->get_sight_y();

  int item_index = location_system->get_entities()->get_item_index(new_x, new_y);
  int ambient_index = location_system->get_entities()->get_ambient_index(new_x, new_y);

  if (item_index != -1) {
    check_item_interact(item_index);
  }
  if (ambient_index != -1) {
    check_ambient_interact(ambient_index);
  }
}

void GameLoopHUDRender::render() {
  render_borders();
  render_nameplate();
  render_inventory();
  render_coordinates();
  render_interact_ability();
}
