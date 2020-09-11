//
// Created by vydra on 9/11/20.
//

#pragma once

#include "components/abs_components/AbsGraficRenderable.hpp"

class SubGraficRenderable : protected AbsGraficRenderable {
 public:
  explicit SubGraficRenderable(unsigned int input_tile_number);
  ~SubGraficRenderable();

  void set_tile(unsigned input_tile_number);

  unsigned get_tile_number() const;
};