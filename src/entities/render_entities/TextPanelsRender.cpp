//
// Created by vydra on 8/12/20.
//

#include "entities/render_entities/TextPanelsRender.h"

#include <string>
#include <vector>

void TextPanelsRender::print_borders(unsigned int in_x, unsigned int in_y, unsigned int out_x, unsigned int out_y) {
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
}

void TextPanelsRender::view_strings_list(unsigned int in_x, unsigned int in_y, unsigned int out_x, unsigned int out_y,
                                         std::vector<std::string *> *input_strings) {
  print_borders(in_x, in_y, out_x, out_y);

  for (unsigned i = 0; i < input_strings->size(); i++) {
    terminal_print(in_x + 2, in_y + 2 + i, input_strings->at(i)->data());
  }
}

void TextPanelsRender::view_parameter_query(unsigned in_x, unsigned int in_y, unsigned int out_x, unsigned int out_y,
                                            std::string *question, std::vector<std::string *> *input_choices,
                                            unsigned int highlighted_choice) {
  print_borders(in_x, in_y, out_x, out_y);

  // draw question
  terminal_print(in_x + 7, in_y + 2, question->data());
  for (unsigned i = 1; i < input_choices->size() + 1; i++) {
    if (highlighted_choice == i) {
      terminal_print(in_x + 3, in_y + 3 + i, "-->");
    }
    terminal_print(in_x + 7, in_y + 3 + i, input_choices->at(i - 1)->data());
  }
}

std::string *TextPanelsRender::view_input_text(unsigned int in_x, unsigned int in_y, unsigned int out_x,
                                               unsigned int out_y, std::string *title,
                                               unsigned int input_max_count_characters) {
  char* temp_characters = new char[input_max_count_characters];
  print_borders(in_x, in_y, out_x, out_y);

  // draw question
  terminal_print(in_x + 7, in_y + 2, title->data());
  terminal_read_str(in_x + 7, in_y + 2, temp_characters, input_max_count_characters);

  auto temp_str = new std::string(temp_characters);
  delete [] temp_characters;
  return temp_str;
}
