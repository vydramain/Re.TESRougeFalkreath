//
// Created by vydra on 8/8/20.
//

#include "entities/Entity.h"

#include <string>

Entity::Entity(const char* input_name) {
  name = new std::string(input_name);
}

Entity::~Entity() {}

std::string* Entity::get_name() const {
  return name;
}

void Entity::set_name(const char* input_name) {
  delete name;
  name = new std::string(input_name);
}
