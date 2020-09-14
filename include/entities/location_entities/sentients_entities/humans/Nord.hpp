//
// Created by vydra on 9/15/20.
//

#pragma once

#include "components/sub_components/SubPseudoRenderable.hpp"
#include "entities/location_entities/sentients_entities/Sentient.h"

class Nord : public Sentient {
 public:
  explicit Nord(const char* input_fio, unsigned input_current_x = 0, unsigned input_current_y = 0,
                    unsigned input_pocket = 10);
  ~Nord() override;
};