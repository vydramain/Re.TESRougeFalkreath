//
// Created by vydra on 8/8/20.
//

#include "ecs/entities/Entity.h"

Entity::Entity(const char* input_name) : name(input_name) {}

const char* Entity::get_name() const {
  return name;
}
