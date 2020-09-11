//
// Created by vydra on 9/11/20.
//

#include "entities/data_entities/GraficRenderData.hpp"

GraficRenderData::GraficRenderData(const char *input_tile_address, unsigned int input_tile_number) {
  tile_address = input_tile_address;
  tile_number = input_tile_number;
}

GraficRenderData::~GraficRenderData() = default;

void GraficRenderData::set_tile_address(const char *input_tile_address) {
  tile_address = input_tile_address;
}

void GraficRenderData::set_tile_number(unsigned int input_tile_number) {
  tile_number = input_tile_number;
}

const char *GraficRenderData::get_tile_address() const {
  return tile_address;
}
unsigned GraficRenderData::get_tile_number() const {
  return tile_number;
}