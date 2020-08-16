//
// Created by vydra on 8/9/20.
//

#pragma once

#include "components/sub_components/SubPseudoRenderable.hpp"
#include "entities/Entity.h"

class LocationsEntity : public Entity, public SubPseudoRenderable {
 public:
  explicit LocationsEntity(const char* input_name, const char* input_tile, unsigned input_color);
  ~LocationsEntity() override;
};
