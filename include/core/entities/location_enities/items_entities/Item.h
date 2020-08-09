//
// Created by vydra on 8/3/20.
//

#pragma once

#include "core/components/sub_components/SubPickable.hpp"
#include "core/entities/location_enities/LocationEntity.h"

class Item : public LocationEntity, public SubPickable {
 public:
  explicit Item(const char* input_name, bool input_pick, unsigned input_x, unsigned input_y);
  ~Item();

  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;
};
