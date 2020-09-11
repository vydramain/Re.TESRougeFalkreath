//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Hedge.h"

Hedge::Hedge(unsigned int input_x, unsigned int input_y)
    : Ambient("Hedge", new PseudoRenderData("h", 0xffb2802e), new GraficRenderData(0xF007), input_x, input_y) {}

Hedge::~Hedge() {}
