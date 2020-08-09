//
// Created by vydra on 8/3/20.
//

#pragma once

#include "ecs/components/sub_components/SubPockets.hpp"
#include "ecs/components/sub_components/SubWalketh.hpp"
#include "ecs/entities/Entity.h"

class Sentient : public Entity, public SubWalketh, public SubPockets {
 public:
  explicit Sentient(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0,
                    unsigned input_pocket_size = 10, unsigned input_wallet = 0);
  Sentient(const Sentient &input_sentient);
  Sentient(Sentient &&input_sentient) noexcept;
  Sentient &operator=(const Sentient &input_race);
  Sentient &operator=(Sentient &&input_race) noexcept;
};
