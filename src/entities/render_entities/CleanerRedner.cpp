//
// Created by vydra on 8/12/20.
//

#include "entities/render_entities/CleanerRender.h"

void CleanerRender::clean_all() {
  terminal_clear();
}

void CleanerRender::clean_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
  for (unsigned i = 0; i < 20; i++) {
    terminal_layer(i);
    terminal_clear_area(in_x, in_y, out_x - in_x + 1, out_y - in_y + 1);
  }
}
