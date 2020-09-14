//
// Created by vydra on 8/26/20.
//

#include "entities/location_entities/ambient_entities/Throne.hpp"

Throne::Throne(unsigned int input_x, unsigned int input_y)
    : Ambient("Throne", new PseudoRenderData("╩", 0xff8d6c64), new GraficRenderData(0xF004), input_x, input_y) {}

Throne::~Throne() {}
