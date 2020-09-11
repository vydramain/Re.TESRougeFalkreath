//
// Created by vydra on 8/26/20.
//

#include "entities/location_entities/ambient_entities/Glacier.hpp"

Glacier::Glacier(unsigned int input_x, unsigned int input_y)
    : Ambient("Glacier", new PseudoRenderData("g", 0xff77a0bd), new GraficRenderData(0xF000), input_x, input_y) {}

Glacier::~Glacier() {}
