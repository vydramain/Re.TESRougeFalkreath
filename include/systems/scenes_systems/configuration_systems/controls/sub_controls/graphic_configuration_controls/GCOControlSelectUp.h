//
// Created by vydra on 7/31/20.
//

#pragma once

#include <vector>

#include "entities/GameConfigurationData.hpp"
#include "entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class GCOControlSelectUp : public IControl {
 private:
  std::vector<ParameterQueryData *> *configuration_data;

 public:
  explicit GCOControlSelectUp(std::vector<ParameterQueryData *> *input_configuration_data)
      : IControl("GCOControlSelectUp") {
    configuration_data = input_configuration_data;
  }
  ~GCOControlSelectUp() override = default;

  void execute() override {
    if (configuration_data->at(0)->get_highlighted() > 1) {
      configuration_data->at(0)->set_highlighted(configuration_data->at(0)->get_highlighted() - 1);
    }
  }
};
