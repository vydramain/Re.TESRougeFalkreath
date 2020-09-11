//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Plant.h"

Plant::Plant(unsigned int input_x, unsigned int input_y)
    : Ambient("Plant", new PseudoRenderData("p", 0xff4fd233), new GraficRenderData(0xF006), input_x, input_y) {}

Plant::~Plant() = default;
