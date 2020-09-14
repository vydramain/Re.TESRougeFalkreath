//
// Created by vydra on 8/3/20.
//

#include <entities/location_entities/sentients_entities/beastfolks/Khadjiit.h>

Khadjiit::Khadjiit(const char* input_fio, unsigned int input_current_x, unsigned int input_current_y,
                   unsigned int input_pocket)
    : Sentient(input_fio, "Khadjiit", new PseudoRenderData("K", 0xffEEEEEE), new GraficRenderData(0xF040),
               input_current_x, input_current_y, input_pocket) {}

Khadjiit::~Khadjiit() = default;
