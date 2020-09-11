//
// Created by vydra on 8/9/20.
//

#pragma once

#include "components/sub_components/SubGraficRenderable.hpp"
#include "components/sub_components/SubPseudoRenderable.hpp"
#include "entities/Entity.h"
#include "entities/data_entities/GraficRenderData.hpp"
#include "entities/data_entities/PseudoRenderData.hpp"

class LocationsEntity : public Entity, public SubPseudoRenderable, public SubGraficRenderable {
 public:
  explicit LocationsEntity(const char* input_name, PseudoRenderData* input_pseudo_data,
                           GraficRenderData* input_grafic_data);
  ~LocationsEntity() override;
};
