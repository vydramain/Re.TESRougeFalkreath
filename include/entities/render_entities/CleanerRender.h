//
// Created by vydra on 8/12/20.
//

#pragma once

#include "./BearLibTerminal.h"

class CleanerRender {
 public:
  static void clean_all();
  static void clean_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);
};
