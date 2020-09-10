//
// Created by vydra on 9/10/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "entities/RenderConfigurationData.hpp"
#include "entities/render_entities/IRender.h"

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