//
// Created by vydra on 8/14/20.
//

#pragma once

#include "core/components/sub_components/SubFloor.hpp"
#include "core/components/sub_components/SubLocatable.hpp"
#include "core/components/sub_components/SubPseudoRenderable.hpp"
#include "core/entities/location_enities/LocationsEntity.h"

class Ambient : public LocationsEntity, public SubLocatable, public SubFloor {
 public:
  explicit Ambient(const char* input_name, const char* input_tile, unsigned input_color,
                   unsigned input_x, unsigned input_y, bool is_floor = false);
  ~Ambient() override;

  bool operator==(const Ambient& rhs) const;
  bool operator!=(const Ambient& rhs) const;
};
