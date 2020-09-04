//
// Created by vydra on 7/31/20.
//

#include "systems_new/IControl.h"

class MMControlSelectDown : public IControl {
 private:
  ParameterQueryData *menu_data;

 public:
  explicit MMControlSelectDown(ParameterQueryData *input_menu_data) : IControl("MMControlSelectDown") {
    menu_data = input_menu_data;
  }
  ~MMControlSelectDown() override = default;

  void execute() override {
    if (menu_data->get_highlighted() < menu_data->get_count_choices()) {
      menu_data->set_highlighted(menu_data->get_highlighted() + 1);
    }
  }
};
