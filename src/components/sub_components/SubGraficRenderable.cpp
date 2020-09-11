//
// Created by vydra on 9/11/20.
//

#include "components/sub_components/SubGraficRenderable.hpp"

SubGraficRenderable::SubGraficRenderable(unsigned int input_tile_number)
    : AbsGraficRenderable(input_tile_number) {}

SubGraficRenderable::~SubGraficRenderable() = default;

void SubGraficRenderable::set_tile(unsigned input_tile_number) {
  tile_number = input_tile_number;
}

unsigned SubGraficRenderable::get_tile_number() const {
  return tile_number;
}
