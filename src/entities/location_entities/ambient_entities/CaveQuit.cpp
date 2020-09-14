//
// Created by vydra on 8/26/20.
//

#include "entities/location_entities/ambient_entities/CaveQuit.hpp"

CaveQuit::CaveQuit(unsigned int input_x, unsigned int input_y)
    : Ambient("CaveQuit", new PseudoRenderData("¶", 0xffdbdbdb), new GraficRenderData(0xF00C), input_x, input_y) {}

CaveQuit::~CaveQuit() {}
