//
// Created by vydra on 8/24/20.
//

#include "entities/location_entities/ambient_entities/WestGate.hpp"

WestGate::WestGate(unsigned int input_x, unsigned int input_y)
    : Ambient("WestGate", new PseudoRenderData("┼", 0xFF909090), new GraficRenderData(0xF00A), input_x, input_y) {}

WestGate::~WestGate() = default;
