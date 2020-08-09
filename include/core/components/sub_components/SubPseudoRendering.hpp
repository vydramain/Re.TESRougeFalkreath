//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/components/abs_components/AbsPseudoRendering.hpp"

class SubPseudoRendering : protected AbsPseudoRendering {
 public:
  explicit SubPseudoRendering(char input_tile, unsigned short int input_color);
  ~SubPseudoRendering();

  char get_tile() const;
  unsigned short get_color();
};
