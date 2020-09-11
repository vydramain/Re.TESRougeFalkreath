//
// Created by vydra on 9/11/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "entities/data_entities/RenderConfigurationData.hpp"
#include "entities/render_entities/IRender.h"

class GameLoopGraficRender : public IRender {
 private:
  RenderConfigurationData *data = nullptr;
  std::map<const char*, unsigned> tiles_map;

 public:
  explicit GameLoopGraficRender(RenderConfigurationData *input_data);

  void render_ambient();
  void render_location_creatures();
  void render_location_items();

  void render() override;
};