//
// Created by vydra on 8/9/20.
//

#include "core/components/sub_components/SubPseudoRendering.hpp"

SubPseudoRendering::SubPseudoRendering(const char input_tile, const unsigned int input_color)
    : AbsPseudoRendering(input_tile, input_color) {}
SubPseudoRendering::~SubPseudoRendering() = default;

char SubPseudoRendering::get_tile() const {
  return tile;
}

unsigned int SubPseudoRendering::get_color() {
  return color;
}
