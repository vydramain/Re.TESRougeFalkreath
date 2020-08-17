//
// Created by vydra on 8/3/20.
//

#pragma once

#include "components/sub_components/SubPseudoRenderable.hpp"
#include "entities/location_entities/sentients_entities/Sentient.h"

class Khadjiit : public Sentient {
 public:
  explicit Khadjiit(const char *input_name, const char* input_tile, unsigned input_color, unsigned input_current_x = 0,
                    unsigned input_current_y = 0, unsigned input_pocket = 10);
  ~Khadjiit() override;
};
