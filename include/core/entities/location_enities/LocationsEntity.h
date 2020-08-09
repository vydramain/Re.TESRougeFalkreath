//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/Entity.h"

class LocationsEntity : public Entity {
 public:
  explicit LocationsEntity(const char* input_name);
  ~LocationsEntity() override;
};
