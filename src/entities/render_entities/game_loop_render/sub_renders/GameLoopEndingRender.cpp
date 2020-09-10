//
// Created by vydra on 8/18/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopEndingRender.hpp"

GameLoopEndingRender::GameLoopEndingRender(RenderConfigurationData *input_data, ParameterQueryData *input_ending_data) {
  data = input_data;
  ending_data = input_ending_data;
}

GameLoopEndingRender::~GameLoopEndingRender() = default;

void GameLoopEndingRender::render() {
  TextPanelsRender::view_parameter_query(0, 0, data->get_screen_mode_x() - 1, data->get_screen_mode_y() - 1,
                                         ending_data->get_title(), ending_data->get_choices(),
                                         ending_data->get_highlighted());
}
