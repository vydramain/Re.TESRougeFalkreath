//
// Created by vydra on 8/14/20.
//

#pragma once

#include "components/sub_components/SubFloor.hpp"
#include "components/sub_components/SubLocatable.hpp"
#include "components/sub_components/SubPseudoRenderable.hpp"
#include "entities/location_entities/LocationsEntity.h"

class Ambient : public LocationsEntity, public SubLocatable, public SubFloor {
 public:
  explicit Ambient(const char* input_name, PseudoRenderData* input_pseudo_data,
                   GraficRenderData* input_grafic_data,
                   unsigned input_x, unsigned input_y, bool is_floor = false);
  ~Ambient() override;

  bool operator==(const Ambient& rhs) const;
  bool operator!=(const Ambient& rhs) const;
};
