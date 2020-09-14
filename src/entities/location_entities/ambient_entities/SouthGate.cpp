//
// Created by vydra on 8/16/20.
//

#include "entities/location_entities/ambient_entities/SouthGate.h"

SouthGate::SouthGate(unsigned int input_x, unsigned int input_y)
    : Ambient("SouthGate", new PseudoRenderData("┼", 0xFFa2a2a2), new GraficRenderData(0xF00A), input_x, input_y) {}

SouthGate::~SouthGate() = default;
