//
// Created by vydra on 8/13/20.
//

#include "entities/render_entities/main_menu_render/MainMenuRender.h"

MainMenuRender::MainMenuRender(unsigned input_screen_x, unsigned input_screen_y, ParameterQueryData *input_menu_data) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  menu_data = input_menu_data;
}

MainMenuRender::~MainMenuRender() = default;

void MainMenuRender::render() {
  CleanerRender::clean_all();
  terminal_color("White");
  TextPanelsRender::view_parameter_query(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, menu_data->get_title(),
                                         menu_data->get_choices(), menu_data->get_count_choices(),
                                         menu_data->get_highlighted());
  terminal_refresh();
}
