//
// Created by vydra on 9/5/20.
//

#include "entities/render_entities/settings_render/SettingsRender.hpp"

SettingsRender::SettingsRender(unsigned int input_screen_x, unsigned int input_screen_y,
                               ParameterQueryData *input_settings_data) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  settings_data = input_settings_data;
}

SettingsRender::~SettingsRender() = default;

void SettingsRender::render() {
  CleanerRender::clean_all();
  terminal_color("White");
  TextPanelsRender::view_parameter_query(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, settings_data->get_title(),
                                         settings_data->get_choices(), settings_data->get_highlighted());
  terminal_refresh();
}
