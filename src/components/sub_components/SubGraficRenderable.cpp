//
// Created by vydra on 9/11/20.
//

#include "components/sub_components/SubGraficRenderable.hpp"

SubGraficRenderable::SubGraficRenderable(const char *input_tile_address, unsigned int input_tile_number)
    : AbsGraficRenderable(input_tile_address, input_tile_number) {}

SubGraficRenderable::~SubGraficRenderable() = default;

void SubGraficRenderable::set_tile(const char *input_tile_address) {
  terminal_set(std::to_string(tile_number).append(": ").append(input_tile_address).data());
}

unsigned SubGraficRenderable::get_tile_number() const {
  return tile_number;
}
