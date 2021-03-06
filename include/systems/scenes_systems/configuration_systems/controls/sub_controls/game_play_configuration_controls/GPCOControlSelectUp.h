//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"
#include "systems/launcher_system/data/GameConfigurationData.hpp"
#include "systems/launcher_system/data/ParameterQueryData.hpp"

class GPCOControlSelectUp : public IControl {
 private:
  ParameterQueryData* settings_data;

 public:
  explicit GPCOControlSelectUp(ParameterQueryData *input_settings_data) : IControl("GPCOControlSelectUp") {
    settings_data = input_settings_data;
  }
  ~GPCOControlSelectUp() override = default;

  void execute() override {
    if (settings_data->get_highlighted() > 1) {
      settings_data->set_highlighted(settings_data->get_highlighted() - 1);
    }
  }
};
