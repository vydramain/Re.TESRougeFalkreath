//
// Created by vydra on 9/10/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "entities/render_entities/IRender.h"
#include "systems/launcher_system/data/RenderConfigurationData.hpp"

class GameLoopPseudoRender : public IRender {
 private:
  RenderConfigurationData *data = nullptr;

 public:
  explicit GameLoopPseudoRender(RenderConfigurationData *input_data);

  void render_ambient();
  void render_location_creatures();
  void render_location_items();

  void render() override;
};