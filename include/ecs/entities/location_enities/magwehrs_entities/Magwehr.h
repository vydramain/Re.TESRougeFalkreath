//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "core/components/sub_components/SubWalketh.hpp"
#include "ecs/entities/Entity.h"

class Magwehr : public Entity, public SubWalketh {
 public:
  explicit Magwehr(const char *input_name, unsigned input_x = 0, unsigned input_y = 0);
  Magwehr(const Magwehr &input_creature);
  Magwehr(Magwehr &&input_creature) noexcept;
  Magwehr &operator=(const Magwehr &input_creature);
  Magwehr &operator=(Magwehr &&input_creature) noexcept;
};
