//
// Created by vydra on 7/31/20.
//

#include "systems/controls_systems/IControl.h"

class MMControlSelectDown : public IControl {
 private:
  MenuData *menu_data;

 public:
  explicit MMControlSelectDown(MenuData *input_menu_data) : IControl("MMControlSelectDown") {
    menu_data = input_menu_data;
  }
  ~MMControlSelectDown() override = default;

  void execute() override {
    if (menu_data->get_highlighted() < menu_data->get_count_choices()) {
      menu_data->set_highlighted(menu_data->get_highlighted() + 1);
    }
  }
};
