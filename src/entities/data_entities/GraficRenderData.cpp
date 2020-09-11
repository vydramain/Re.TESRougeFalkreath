//
// Created by vydra on 9/11/20.
//

#include "entities/data_entities/GraficRenderData.hpp"

GraficRenderData::GraficRenderData(unsigned int input_tile_number) {
  tile_number = input_tile_number;
}

GraficRenderData::~GraficRenderData() = default;

void GraficRenderData::set_tile_number(unsigned int input_tile_number) {
  tile_number = input_tile_number;
}

unsigned GraficRenderData::get_tile_number() const {
  return tile_number;
}
