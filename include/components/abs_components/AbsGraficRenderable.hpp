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
  explicit AbsGraficRenderable(const char* input_tile_address, unsigned int input_tile_number) {
    tile_number = input_tile_number;
    terminal_set(std::to_string(input_tile_number).append(": ").append(input_tile_address).data());
  }
  ~AbsGraficRenderable() = default;
};
