//
// Created by vydra on 8/12/20.
//

#pragma once

#include "./BearLibTerminal.h"

class TextPanelsRender {
 public:
  static void view_strings_list(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y, std::string **input_strings,
                        unsigned input_count_strings);
  static void view_parameter_query(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y,
                                          std::string *question, std::string **input_choices,
                                          unsigned input_count_choices, unsigned highlighted_choice);
};
