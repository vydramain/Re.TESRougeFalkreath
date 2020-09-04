//
// Created by vydra on 7/31/20.
//

#pragma once

#include "entities/ParameterQueryData.hpp"
#include "systems/IControl.h"

class SEControlSelectUp : public IControl {
 private:
  ParameterQueryData* settings_data;

 public:
  explicit SEControlSelectUp(ParameterQueryData* input_settings_data) : IControl("SEControlSelectUp") {
    settings_data = input_settings_data;
  }
  ~SEControlSelectUp() override = default;

  void execute() override {
    if (settings_data->get_highlighted() > 1) {
      settings_data->set_highlighted(settings_data->get_highlighted() - 1);
    }
  }
};
