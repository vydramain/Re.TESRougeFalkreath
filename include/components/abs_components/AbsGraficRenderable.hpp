//
// Created by vydra on 9/10/20.
//

#pragma once

#include <cstdlib>
#include <string>

#include "./BearLibTerminal.h"

class AbsGraficRenderable {
 protected:
  unsigned tile_number;

 public:
  explicit AbsGraficRenderable(unsigned int input_tile_number) {
    tile_number = input_tile_number;
  }
  ~AbsGraficRenderable() = default;
};
