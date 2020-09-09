//
// Created by vydra on 7/31/20.
//

#pragma once

#include "entities/GameConfigurationData.hpp"
#include "entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class GCOControlSelectEnter : public IControl {
  GameConfigurationData* global_configuration_data;
  ParameterQueryData* configuration_data;

 public:
  explicit GCOControlSelectEnter(ParameterQueryData* input_configuration_data,
                                 GameConfigurationData* input_global_configuration_data)
      : IControl("GCOControlSelectEnter") {
    configuration_data = input_configuration_data;
    global_configuration_data = input_global_configuration_data;
  }
  ~GCOControlSelectEnter() override = default;

  void execute() override {
    if (configuration_data->get_highlighted() == 1) {
    }
    if (configuration_data->get_highlighted() == 2) {
    }
  }
};
