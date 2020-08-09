//
// Created by vydra on 8/9/20.
//

#pragma once

class AbsPseudoRendering {
 protected:
  char tile;
  unsigned int color;

 public:
  explicit AbsPseudoRendering(const char input_tile, const unsigned int input_color) : tile(input_tile), color(input_color) {}
  ~AbsPseudoRendering() = default;
};
