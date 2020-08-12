//
// Created by vydra on 8/12/20.
//

#include "core/entities/render_entities/CleanerRender.h"

void CleanerRender::clean_all() {
  terminal_clear();
}

void CleanerRender::clean_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
  terminal_clear_area(in_x, in_y, out_x, out_y);
}
