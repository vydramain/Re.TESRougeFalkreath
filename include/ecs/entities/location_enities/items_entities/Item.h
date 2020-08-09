//
// Created by vydra on 8/3/20.
//

#pragma once

#include "ecs/components/sub_components/SubPickable.hpp"
#include "ecs/entities/Entity.h"

class Item : public Entity, public SubPickable {
 public:
  explicit Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y);
  ~Item();

  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;
};
