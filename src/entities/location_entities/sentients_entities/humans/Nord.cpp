//
// Created by vydra on 9/15/20.
//

#include "entities/location_entities/sentients_entities/humans/Nord.hpp"

Nord::Nord(const char* input_fio, unsigned int input_current_x, unsigned int input_current_y,
                   unsigned int input_pocket)
    : Sentient(new SentientParametersData(input_current_x, input_current_y, 100, 90, 130, 10, input_pocket, "Nord",
                                          input_fio, new PseudoRenderData("N", 0xffEEEEEE),
                                          new GraficRenderData(0xF045))) {}

Nord::~Nord() = default;
