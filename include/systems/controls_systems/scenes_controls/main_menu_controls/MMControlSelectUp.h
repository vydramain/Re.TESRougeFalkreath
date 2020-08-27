//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class MMControlSelectUp : public IControl {
 private:
  ParameterQueryData* menu_data;

 public:
  explicit MMControlSelectUp(ParameterQueryData* input_menu_data) : IControl("MMControlSelectUp") {
    menu_data = input_menu_data;
  }
  ~MMControlSelectUp() override = default;

  void execute() override {
    if (menu_data->get_highlighted() > 1) {
      menu_data->set_highlighted(menu_data->get_highlighted() - 1);
    }
  }
};
