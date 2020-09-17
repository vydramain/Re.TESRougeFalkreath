//
// Created by vydra on 8/17/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopHUDRender.hpp"

#include <string>
#include <vector>

void GameLoopHUDRender::render_parameter(std::string input_string, unsigned int input_parameter, unsigned input_x,
                                         unsigned input_y) {
  char temp_char[7];
  snprintf(temp_char, (size_t) "%u", "%u", input_parameter);
  terminal_print(input_x, input_y, input_string.data());
  terminal_print(input_x + input_string.size(), input_y, temp_char);
}

GameLoopHUDRender::GameLoopHUDRender(RenderConfigurationData *input_data, ParameterQueryDataSet *input_query_data_set) {
  data = input_data;
  query_data_set = input_query_data_set;
}

GameLoopHUDRender::~GameLoopHUDRender() {
  data = nullptr;
  query_data_set = nullptr;
}

std::vector<std::string *> *GameLoopHUDRender::prepare_string_message(std::string *input_text) const {
  unsigned counter_words = 0;
  unsigned counter_strings = 0;
  auto return_text = new std::vector<std::string *>;
  auto words = CCMech::split(input_text);
  return_text->push_back(new std::string);
  for (auto &word : words) {
    counter_words += word->size();
    if (counter_words > data->get_text_size() * 1.8) {
      counter_words = word->size();
      counter_strings++;
      return_text->push_back(new std::string);
    }
    return_text->at(counter_strings)->append(*word);
  }
  return return_text;
}

void GameLoopHUDRender::view_string_message(std::vector<std::string *> *input_text) {
  if (data->get_camera_position_x() + (data->get_passive_zone_out_x() / 2) < data->get_target()->get_current_x()) {
    TextPanelsRender::view_strings_list(1, data->get_passive_zone_out_y() - 5 - input_text->size(),
                                        data->get_message_left_out_x() - 2, data->get_passive_zone_out_y() - 2,
                                        input_text);
  } else {
    TextPanelsRender::view_strings_list(
        data->get_message_right_in_x(), data->get_passive_zone_out_y() - 5 - input_text->size(),
        data->get_passive_zone_out_x() - 2, data->get_passive_zone_out_y() - 2, input_text);
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
  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "Door") == 0) {
    if (data->get_world_system()->get_current_map()->get_entities_system()->get_ambient(input_index)->get_floor()) {
      produce_string_message(new std::string("Нажмите 'E', чтобы закрыть"));
    } else {
      produce_string_message(new std::string("Нажмите 'E', чтобы открыть"));
    }
  }

  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "SouthGate") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы отправиться в дальние земли"));
  }

  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "EastGate") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы отправиться в восточный лес"));
  }

  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "WestGate") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы вернуться в Фолкрит"));
  }

  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "UpperHatch") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы спуститься в подземелье Кровавого Трона"));
  }

  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "LowerHatch") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы подняться в руины форта Кровавого Трона"));
  }

  if (std::strcmp(data->get_world_system()
                      ->get_current_map()
                      ->get_entities_system()
                      ->get_ambient(input_index)
                      ->get_name()
                      ->data(),
                  "CaveQuit") == 0) {
    produce_string_message(new std::string("Нажмите 'E', чтобы выйти из подземелья"));
  }
}

void GameLoopHUDRender::render_borders() {
  terminal_layer(10);
  terminal_color(0xffffffff);
  for (unsigned i = 0; i < data->get_passive_zone_out_y(); i++) {
    terminal_print(data->get_passive_zone_out_x(), i, "│");
  }

  terminal_print(data->get_passive_zone_out_x(), 9, "├");
  terminal_print(data->get_passive_zone_out_x(), data->get_passive_zone_out_y() - 5, "├");
  for (unsigned i = 0; i < data->get_screen_mode_x() - data->get_passive_zone_out_x(); i++) {
    terminal_print(data->get_passive_zone_out_x() + i + 1, 9, "─");
    terminal_print(data->get_passive_zone_out_x() + i + 1, data->get_passive_zone_out_y() - 5, "─");
  }
}

void GameLoopHUDRender::render_nameplate() {
  terminal_color(0xffffffff);
  terminal_print(data->get_passive_zone_out_x() + 1, 1, "Имя:");
  terminal_print(
      data->get_passive_zone_out_x() + 6, 1,
      data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_nickname()->data());
  terminal_print(data->get_passive_zone_out_x() + 1, 2, "Раса:");
  terminal_print(data->get_passive_zone_out_x() + 7, 2,
                 data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_name()->data());
  terminal_print(data->get_passive_zone_out_x() + 1, 3, "Статус:");
  //  terminal_print(data->get_passive_zone_out_x() + 10, 3,
  //  data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_status());

  terminal_color(0xFFFF4444);
  render_parameter(std::string("ОЗ:"),
                   data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_hp(),
                   data->get_passive_zone_out_x() + 1, 4);

  terminal_color(0xFF44ff44);
  render_parameter(std::string("ОД:"),
                   data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_ap(),
                   data->get_passive_zone_out_x() + 1, 5);

  terminal_color(0xFF6666FF);
  render_parameter(std::string("ОM:"),
                   data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_mp(),
                   data->get_passive_zone_out_x() + 1, 6);
}

void GameLoopHUDRender::render_inventory() {
  terminal_color(0xffffffff);
  terminal_print(data->get_passive_zone_out_x() + 1, 11, "Карманы:");
  render_parameter(std::string("Кошель:"),
                   data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_wallet(),
                   data->get_passive_zone_out_x() + 1, data->get_passive_zone_out_y() - 7);
}

void GameLoopHUDRender::render_coordinates() {
  terminal_color(0xffffffff);
  terminal_print(data->get_passive_zone_out_x() + 1, data->get_passive_zone_out_y() - 3, "Координаты:");
  char x[4], y[4];
  snprintf(x, (size_t) "%u", "%u",
           data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_current_x());
  snprintf(y, (size_t) "%u", "%u",
           data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_current_y());
  terminal_print(data->get_passive_zone_out_x() + 15, data->get_passive_zone_out_y() - 3, x);
  terminal_print(data->get_passive_zone_out_x() + 20, data->get_passive_zone_out_y() - 3, y);
}

void GameLoopHUDRender::render_interact_ability() {
  terminal_color(0xffffffff);
  unsigned new_x = data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_sight_x();
  unsigned new_y = data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_sight_y();

  int item_index = data->get_world_system()->get_current_map()->get_entities_system()->get_item_index(new_x, new_y);
  int ambient_index =
      data->get_world_system()->get_current_map()->get_entities_system()->get_ambient_index(new_x, new_y);

  if (item_index != -1) {
    check_item_interact(item_index);
  }
  if (ambient_index != -1) {
    check_ambient_interact(ambient_index);
  }
}

void GameLoopHUDRender::render_fight_condition() {
  if (data->get_world_system()->get_current_map()->get_entities_system()->get_player()->get_current_condition() ==
      AbsSentientCondition::FIGHT) {
    Sentient *opponent = nullptr;
    for (unsigned i = 1; i < data->get_world_system()->get_current_map()->get_entities_system()->get_sentients_size();
         i++) {
      if (data->get_world_system()
              ->get_current_map()
              ->get_entities_system()
              ->get_sentient(i)
              ->get_current_condition() == AbsSentientCondition::FIGHT) {
        opponent = data->get_world_system()->get_current_map()->get_entities_system()->get_sentient(i);
      }
      break;
    }
    auto temp_data = query_data_set->get_data(new std::string("combat_data"));
    auto temp_strings = new std::vector<std::string *>();
    temp_strings->push_back(new std::string("Противник:"));
    temp_strings->push_back(new std::string(*opponent->get_nickname()));
    TextPanelsRender::view_strings_list(data->get_active_zone_in_x(), data->get_active_zone_in_y(),
                                        data->get_active_zone_out_x(), data->get_active_zone_out_y() + 3, temp_strings);
    render_parameter(std::string("ОД:"), opponent->get_hp(), data->get_active_zone_in_x() + 2,
                     data->get_active_zone_in_y() + 4);
    temp_strings->clear();
    temp_strings->push_back(temp_data->get_choice(0));
    temp_strings->push_back(temp_data->get_choice(1));
    TextPanelsRender::view_parameter_query(data->get_active_zone_in_x(), data->get_active_zone_in_y() + 6,
                                           data->get_active_zone_out_x(), data->get_active_zone_out_y() + 3,
                                           temp_data->get_title(), temp_strings, temp_data->get_highlighted());
    delete temp_strings;
  }
}

void GameLoopHUDRender::render() {
  render_borders();
  render_nameplate();
  render_inventory();
  render_coordinates();
  render_interact_ability();
  render_fight_condition();
}
