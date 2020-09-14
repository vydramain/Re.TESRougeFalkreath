//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Water.h"

Water::Water(unsigned int input_x, unsigned int input_y)
    : Ambient("Water", new PseudoRenderData("~", 0xFF355cff), new GraficRenderData(0xF001), input_x, input_y) {}

Water::~Water() = default;
