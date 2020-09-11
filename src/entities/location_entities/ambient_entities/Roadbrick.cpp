//
// Created by vydra on 8/14/20.
//

#include "entities/location_entities/ambient_entities/Roadbrick.h"

Roadbrick::Roadbrick(unsigned int input_x, unsigned int input_y)
    : Ambient("Roadbrick", new PseudoRenderData(".", 0xFF444444), new GraficRenderData(0xF005), input_x, input_y,
              true) {}

Roadbrick::~Roadbrick() = default;
