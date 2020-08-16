//
// Created by vydra on 8/9/20.
//

#include "components/sub_components/SubPseudoRenderable.hpp"

SubPseudoRenderable::SubPseudoRenderable(const char* input_tile, const unsigned int input_color)
    : AbsPseudoRenderable(input_tile, input_color) {}

SubPseudoRenderable::~SubPseudoRenderable() = default;

void SubPseudoRenderable::set_tile(const char* input_tile) {
  tile = input_tile;
}

void SubPseudoRenderable::set_color(unsigned int input_color) {
  color = input_color;
}

const char* SubPseudoRenderable::get_tile() const {
  return tile;
}

unsigned int SubPseudoRenderable::get_color() const {
  return color;
}
