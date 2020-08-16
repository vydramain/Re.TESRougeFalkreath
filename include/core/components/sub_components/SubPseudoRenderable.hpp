//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/components/abs_components/AbsLocatable.hpp"
#include "core/components/abs_components/AbsPseudoRenderable.hpp"

class SubPseudoRenderable : protected AbsPseudoRenderable {
 public:
  explicit SubPseudoRenderable(const char* input_tile,
                               unsigned input_color);
  ~SubPseudoRenderable();

  void set_tile(const char* input_tile);
  void set_color(unsigned input_color);

  const char* get_tile() const;
  unsigned get_color() const;
};
