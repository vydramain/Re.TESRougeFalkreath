//
// Created by vydra on 8/3/20.
//

#include <entities/location_entities/sentients_entities/beastfolks/Khajiit.h>

Khajiit::Khajiit(const char* input_fio, unsigned int input_current_x, unsigned int input_current_y,
                   unsigned int input_pocket)
    : Sentient(new SentientParametersData(input_current_x, input_current_y, 100, 90, 130, 10, input_pocket, "Khajiit",
                                          input_fio, new PseudoRenderData("K", 0xffEEEEEE),
                                          new GraficRenderData(0xF040))) {}

Khajiit::~Khajiit() = default;
