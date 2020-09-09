//
// Created by vydra on 8/12/20.
//

#pragma once

#include <string>
#include <vector>

#include "./BearLibTerminal.h"

class TextPanelsRender {
 public:
  static void view_strings_list(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y,
                                std::vector<std::string *> *input_strings);
  static void view_parameter_query(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y, std::string *question,
                                   std::vector<std::string *> *input_choices, unsigned highlighted_choice);
};
