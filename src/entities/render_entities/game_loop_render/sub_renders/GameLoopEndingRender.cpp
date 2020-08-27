//
// Created by vydra on 8/18/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopEndingRender.hpp"

GameLoopEndingRender::GameLoopEndingRender(ParameterQueryData *input_ending_data) {
  ending_data = input_ending_data;
}

GameLoopEndingRender::~GameLoopEndingRender() = default;

void GameLoopEndingRender::update_fields(unsigned int input_screen_x, unsigned int input_screen_y) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;
}

void GameLoopEndingRender::render() {
  TextPanelsRender::view_parameter_query(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, ending_data->get_title(),
                                         ending_data->get_choices(), ending_data->get_count_choices(),
                                         ending_data->get_highlighted());
}
