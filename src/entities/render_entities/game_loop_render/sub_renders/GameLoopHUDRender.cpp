//
// Created by vydra on 8/17/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopHUDRender.hpp"

#include <string>
#include <vector>

GameLoopHUDRender::GameLoopHUDRender(IWorldSystem *input_world_system, const Sentient *input_target)
    : world_system(input_world_system), target(input_target) {}

GameLoopHUDRender::~GameLoopHUDRender() {
  world_system = nullptr;
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

  update_message_data();

  camera_position_x = input_camera_position_x;
  camera_position_y = input_camera_position_y;
}

void GameLoopHUDRender::update_camera(unsigned int input_camera_position_x, unsigned int input_camera_position_y) {
  camera_position_x = input_camera_position_x;
  camera_position_y = input_camera_position_y;
}

void GameLoopHUDRender::update_message_data() {
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

std::vector<std::string *> *GameLoopHUDRender::prepare_string_message(std::string *input_text) const {
  unsigned counter_words = 0;
  unsigned counter_strings = 0;
  auto return_text = new std::vector<std::string *>;
  auto words = CCMech::split(input_text);
  return_text->push_back(new std::string);
  for (auto &word : words) {
    counter_words += word->size();
    if (counter_words > text_size * 1.8) {
      counter_words = word->size();
      counter_strings++;
      return_text->push_back(new std::string);
    }
    return_text->at(counter_strings)->append(*word);
  }
  return return_text;
}

void GameLoopHUDRender::view_string_message(std::vector<std::string *> *input_text) {
  if (camera_position_x + (passive_zone_out_x / 2) < target->get_current_x()) {
    CleanerRender::clean_area(1, passive_zone_out_y - 5 - input_text->size(), message_left_out_x,
                              passive_zone_out_y - 1);
    TextPanelsRender::view_strings_list(1, passive_zone_out_y - 5 - input_text->size(), message_left_out_x,
                                        passive_zone_out_y - 2, input_text);
  } else {
    CleanerRender::clean_area(message_right_in_x, passive_zone_out_y - 5 - input_text->size(), passive_zone_out_x - 1,
                              passive_zone_out_y - 1);
    TextPanelsRender::view_strings_list(message_right_in_x, passive_zone_out_y - 5 - input_text->size(),
                                        passive_zone_out_x - 2, passive_zone_out_y - 2, input_text);
  }
}

void GameLoopHUDRender::produce_string_message(std::string *input_text) {
  auto temp_text = prepare_string_message(input_text);
  terminal_color(0xffffffff);
  view_string_message(temp_text);
  temp_text->clear();
  delete temp_text;
}

void GameLoopHUDRender::check_item_interact(unsigned input_index) {
  produce_string_message(new std::string("Нажмите 'E', для взаимодействия"));
}

void GameLoopHUDRender::check_ambient_interact(unsigned input_index) {
  terminal_color(0xffffffff);
  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "Door") == 0) {
    if (world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_floor()) {
      produce_string_message(new std::string("Нажмите 'E', чтобы закрыть"));
    } else {
      produce_string_message(new std::string("Нажмите 'E', чтобы открыть"));
    }
  }

  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "SouthGate") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы отправиться в дальние земли"));
  }

  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "EastGate") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы отправиться в восточный лес"));
  }

  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "WestGate") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы вернуться в Фолкрит"));
  }

  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "UpperHatch") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы спуститься в подземелье Кровавого Трона"));
  }

  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "LowerHatch") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы подняться в руины форта Кровавого Трона"));
  }

  if (std::strcmp(world_system->get_current_map()->get_entities_system()->get_ambient(input_index)->get_name(),
                  "CaveQuit") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы выйти из подземелья"));
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
  terminal_print(passive_zone_out_x + 1, 11, "Карманы:");
  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 7, "Кошель:");
  char wallet[7];
  snprintf(wallet, (size_t) "%u", "%u",
           world_system->get_current_map()->get_entities_system()->get_player()->get_wallet());
  terminal_print(passive_zone_out_x + 9, passive_zone_out_y - 7, wallet);
}

void GameLoopHUDRender::render_coordinates() {
  terminal_color(0xffffffff);
  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 3, "Координаты:");
  char x[4], y[4];
  snprintf(x, (size_t) "%u", "%u",
           world_system->get_current_map()->get_entities_system()->get_player()->get_current_x());
  snprintf(y, (size_t) "%u", "%u",
           world_system->get_current_map()->get_entities_system()->get_player()->get_current_y());
  terminal_print(passive_zone_out_x + 15, passive_zone_out_y - 3, x);
  terminal_print(passive_zone_out_x + 20, passive_zone_out_y - 3, y);
}

void GameLoopHUDRender::render_interact_ability() {
  terminal_color(0xffffffff);
  unsigned new_x = world_system->get_current_map()->get_entities_system()->get_player()->get_sight_x();
  unsigned new_y = world_system->get_current_map()->get_entities_system()->get_player()->get_sight_y();

  int item_index = world_system->get_current_map()->get_entities_system()->get_item_index(new_x, new_y);
  int ambient_index = world_system->get_current_map()->get_entities_system()->get_ambient_index(new_x, new_y);

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
