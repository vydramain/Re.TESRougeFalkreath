//
// Created by vydra on 8/18/20.
//

#pragma once

#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "systems/launcher_system/data/ParameterQueryData.hpp"
#include "systems/launcher_system/data/RenderConfigurationData.hpp"

class GameLoopEndingRender : public IRender {
 private:
  RenderConfigurationData *data = nullptr;
  ParameterQueryData *ending_data;

 public:
  explicit GameLoopEndingRender(RenderConfigurationData *input_data, ParameterQueryData *input_ending_data);
  ~GameLoopEndingRender() override;

  void render() override;
};
