//
// Created by vydra on 9/11/20.
//

#include "entities/data_entities/PseudoRenderData.hpp"

PseudoRenderData::PseudoRenderData(const char *input_tile, unsigned input_color) {
  tile = input_tile;
  color = input_color;
}

PseudoRenderData::~PseudoRenderData() = default;

void PseudoRenderData::set_tile(const char *input_tile) {
  tile = input_tile;
}

void PseudoRenderData::set_color(unsigned int input_color) {
  color = input_color;
}

const char *PseudoRenderData::get_tile() const {
  return tile;
}

unsigned PseudoRenderData::get_color() const {
  return color;
}
