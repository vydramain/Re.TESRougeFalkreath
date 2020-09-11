//
// Created by vydra on 8/26/20.
//

#include "entities/location_entities/ambient_entities/LowerHatch.hpp"

LowerHatch::LowerHatch(unsigned int input_x, unsigned int input_y)
    : Ambient("LowerHatch", new PseudoRenderData("©", 0xff99692c),
                                new GraficRenderData(0xF008), input_x, input_y) {}

LowerHatch::~LowerHatch() {}
