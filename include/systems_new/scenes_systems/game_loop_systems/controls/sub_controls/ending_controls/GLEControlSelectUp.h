//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems_new/IControl.h"

class GLEControlSelectUp : public IControl {
 private:
  ParameterQueryData *ending_data;

 public:
  explicit GLEControlSelectUp(ParameterQueryData *input_ending_data)
      : IControl("GLEControlSelectUp") {
    ending_data = input_ending_data;
  }
  ~GLEControlSelectUp() override = default;

  void execute() override {
    if (ending_data->get_highlighted() > 1) {
      ending_data->set_highlighted(ending_data->get_highlighted() - 1);
    }
  }
};
