//
// Created by vydra on 8/3/20.
//

#include <core/entities/location_enities/sentients_entities/beastfolks/Khadjiit.h>

Khadjiit::Khadjiit(const char *input_name, const char* input_tile, unsigned input_color,
                   unsigned int input_current_x, unsigned int input_current_y, unsigned int input_pocket)
    : Sentient(input_name, input_tile, input_color, input_current_x, input_current_y, input_pocket) {}

Khadjiit::~Khadjiit() = default;
