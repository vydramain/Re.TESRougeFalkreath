//
// Created by vydra on 7/31/20.
//

#pragma once

#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class GPCOControlSelectEnter : public IControl {
  GameConfigurationData* global_configuration_data;
  ParameterQueryData* configuration_data;

 public:
  explicit GPCOControlSelectEnter(ParameterQueryData* input_configuration_data,
                                  GameConfigurationData* input_global_configuration_data)
      : IControl("GPCOControlSelectEnter") {
    configuration_data = input_configuration_data;
    global_configuration_data = input_global_configuration_data;
  }
  ~GPCOControlSelectEnter() override = default;

  void execute() override {
    if (configuration_data->get_highlighted() == 1) {
      global_configuration_data->set_rouge(true);
    }
    if (configuration_data->get_highlighted() == 2) {
      global_configuration_data->set_rouge(false);
    }
  }
};
