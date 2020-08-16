//
// Created by vydra on 8/9/20.
//

#pragma once

class AbsPseudoRenderable {
 protected:
  const char* tile;
  unsigned int color;

 public:
  explicit AbsPseudoRenderable(const char* input_tile, const unsigned int input_color) {
    tile = input_tile;
    color = input_color;
  }
  ~AbsPseudoRenderable() = default;
};
