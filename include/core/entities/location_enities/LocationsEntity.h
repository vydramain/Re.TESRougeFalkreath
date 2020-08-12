//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/Entity.h"
#include "core/components/sub_components/SubPseudoRenderable.hpp"

class LocationsEntity : public Entity, public SubPseudoRenderable {
 public:
  explicit LocationsEntity(const char* input_name, char input_tile, unsigned input_color);
  ~LocationsEntity() override;
};
