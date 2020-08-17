//
// Created by vydra on 8/3/20.
//

#pragma once

#include "components/sub_components/SubPickable.hpp"
#include "components/sub_components/SubPseudoRenderable.hpp"
#include "entities/location_entities/LocationsEntity.h"

class Item : public LocationsEntity, public SubPickable {
 public:
  explicit Item(const char* input_name, const char* input_tile, unsigned input_color,
                unsigned input_x, unsigned input_y);
  ~Item() override;

  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;
};
