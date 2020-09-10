//
// Created by vydra on 9/11/20.
//

#pragma once

#include "components/abs_components/AbsGraficRenderable.hpp"

class SubGraficRenderable : protected AbsGraficRenderable {
 public:
  explicit SubGraficRenderable(const char* input_tile_address, unsigned int input_tile_number);
  ~SubGraficRenderable();

  void set_tile(const char* input_tile_address);

  unsigned get_tile_number() const;
};