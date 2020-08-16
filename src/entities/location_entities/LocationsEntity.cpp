//
// Created by vydra on 8/9/20.
//

#include "entities/location_entities/LocationsEntity.h"

LocationsEntity::LocationsEntity(const char* input_name, const char* input_tile, unsigned input_color)
    : Entity(input_name), SubPseudoRenderable(input_tile, input_color) {}
LocationsEntity::~LocationsEntity() = default;
