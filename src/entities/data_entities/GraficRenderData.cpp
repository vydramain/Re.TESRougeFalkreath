//
// Created by vydra on 9/11/20.
//

#include "entities/location_entities/data/GraficRenderData.hpp"

GraficRenderData::GraficRenderData(unsigned int input_tile_number) {
  tile_number = input_tile_number;
}

GraficRenderData::~GraficRenderData() = default;

void GraficRenderData::set_grafic_tile(unsigned int input_tile_number) {
  tile_number = input_tile_number;
}

unsigned GraficRenderData::get_grafic_tile() const {
  return tile_number;
}
