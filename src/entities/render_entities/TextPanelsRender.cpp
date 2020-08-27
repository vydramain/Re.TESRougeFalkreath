//
// Created by vydra on 8/12/20.
//

#include "entities/render_entities/TextPanelsRender.h"

void TextPanelsRender::view_text(unsigned int in_x, unsigned int in_y, unsigned int out_x, unsigned int out_y,
                                 const char **input_strings, unsigned input_count_strings) {
  // cleaning up Area for message
  for (unsigned j = 0; j < out_y - in_y; j++) {
    for (unsigned i = 0; i < out_x - in_x; i++) {
      terminal_put(in_x + i, in_y + j, ' ');
    }
  }

  // draw borders
  terminal_print(in_x, in_y, "┌");
  terminal_print(out_x, in_y, "┐");
  terminal_print(in_x, out_y, "└");
  terminal_print(out_x, out_y, "┘");
  for (unsigned j = 0; j < out_y - in_y - 1; j++) {
    terminal_print(in_x, in_y + 1 + j, "│");
    terminal_print(out_x, in_y + 1 + j, "│");
  }
  for (unsigned i = 0; i < out_x - in_x - 1; i++) {
    terminal_print(in_x + 1 + i, in_y, "─");
    terminal_print(in_x + 1 + i, out_y, "─");
  }

  for (unsigned int i = 0; i < input_count_strings; i++) {
    terminal_print(in_x + 2, in_y + 2 + i, input_strings[i]);
  }
}

void TextPanelsRender::view_parameter_query(unsigned in_x, unsigned int in_y, unsigned int out_x,
                                                   unsigned int out_y, std::string *question,
                                                   std::string **input_choices, unsigned int input_count_choices,
                                                   unsigned int highlighted_choice) {
  // cleaning up area
  for (unsigned ii(0); ii < (out_y - in_y); ii++) {
    for (unsigned i(0); i < (out_x - in_x); i++) {
      terminal_put(in_x + i, in_y + ii, ' ');
    }
  }

  // draw borders
  terminal_print(in_x, in_y, "┌");
  terminal_print(out_x, in_y, "┐");
  terminal_print(in_x, out_y, "└");
  terminal_print(out_x, out_y, "┘");
  for (unsigned j = 0; j < out_y - in_y - 1; j++) {
    terminal_print(in_x, in_y + 1 + j, "│");
    terminal_print(out_x, in_y + 1 + j, "│");
  }
  for (unsigned i = 0; i < out_x - in_x - 1; i++) {
    terminal_print(in_x + 1 + i, in_y, "─");
    terminal_print(in_x + 1 + i, out_y, "─");
  }

  // draw question
  terminal_print(in_x + 7, in_y + 2, question->data());
  for (unsigned i(1); i < input_count_choices + 1; i++) {
    if (highlighted_choice == i) {
      terminal_print(in_x + 3, in_y + 3 + i, "-->");
    }
    terminal_print(in_x + 7, in_y + 3 + i, input_choices[i - 1]->data());
  }
}
