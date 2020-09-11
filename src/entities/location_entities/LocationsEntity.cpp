//
// Created by vydra on 8/9/20.
//

#include "entities/location_entities/LocationsEntity.h"

LocationsEntity::LocationsEntity(const char* input_name, PseudoRenderData* input_pseudo_data,
                                 GraficRenderData* input_grafic_data)
    : Entity(input_name),
      SubPseudoRenderable(input_pseudo_data->get_pseudo_tile(), input_pseudo_data->get_pseudo_color()),
      SubGraficRenderable(input_grafic_data->get_grafic_tile()) {}

LocationsEntity::~LocationsEntity() = default;
