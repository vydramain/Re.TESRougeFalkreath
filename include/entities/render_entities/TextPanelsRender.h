//
// Created by vydra on 8/12/20.
//

#pragma once

#include "./BearLibTerminal.h"

class TextPanelsRender {
 public:
  static void view_text(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y,
                        const char* input_first_string = "null", const char* input_second_string = "null");
  static void view_question_with_a_choice(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y,
                                          const char* question, const char** input_choices,
                                          unsigned input_count_choices, unsigned highlighted_choice);
};
