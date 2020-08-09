//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/Entity.h"

class LocationEntity : public Entity {
 public:
  explicit LocationEntity(const char* input_name);
  ~LocationEntity() override;
};
