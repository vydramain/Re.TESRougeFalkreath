//
// Created by vydra on 9/11/20.
//

#pragma once

#include <map>

#include "./BearLibTerminal.h"
#include "entities/render_entities/IRender.h"
#include "systems/launcher_system/data/RenderConfigurationData.hpp"

class GameLoopGraficRender : public IRender {
 private:
  RenderConfigurationData *data = nullptr;
  std::map<const char*, unsigned> tiles_map;

 public:
  explicit GameLoopGraficRender(RenderConfigurationData *input_data);

  void render_ground();
  void render_ambient();
  void render_location_items();
  void render_location_creatures();

  void render() override;
};