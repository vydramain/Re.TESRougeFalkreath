//
// Created by vydra on 8/3/20.
//

#pragma once

#include "ecs/entities/location_enities/sentients_entities/Sentient.h"

class Khadjiit : public Sentient {
 public:
  explicit Khadjiit(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0,
                    unsigned input_pocket = 10);
};
