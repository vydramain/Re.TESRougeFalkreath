//
// Created by vydra on 8/13/20.
//

#include "core/entities/render_entities/main_menu_render/MainMenuRender.h"
MainMenuRender::MainMenuRender(unsigned input_screen_x, unsigned input_screen_y, const char *input_question,
                               const char **input_choices, unsigned int input_count_choices,
                               unsigned int *input_highlighted_choice) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  question = input_question;
  choices = input_choices;
  count_choices = input_count_choices;
  highlighted_choice = input_highlighted_choice;
}

MainMenuRender::~MainMenuRender() = default;

void MainMenuRender::render() {
  CleanerRender::clean_all();
  TextPanelsRender::view_question_with_a_choice(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, question, choices,
                                                count_choices, *highlighted_choice);
  terminal_refresh();
}
