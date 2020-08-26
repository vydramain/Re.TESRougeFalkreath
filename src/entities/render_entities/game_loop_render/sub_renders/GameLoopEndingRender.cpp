//
// Created by vydra on 8/18/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopEndingRender.hpp"

GameLoopEndingRender::GameLoopEndingRender(unsigned int *input_highlighted) {
  highlighted = input_highlighted;
}

GameLoopEndingRender::~GameLoopEndingRender() {
  highlighted = nullptr;
}

void GameLoopEndingRender::update_fields(unsigned int input_screen_x, unsigned int input_screen_y) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;
}

void GameLoopEndingRender::render() {
  TextPanelsRender::view_question_with_a_choice(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1,
                                                question, choices, count_choices, *highlighted);
}
