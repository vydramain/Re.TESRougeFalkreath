//
// Created by vydra on 7/31/20.
//

#include "systems/controls_systems/IControl.h"

class GLEControlSelectDown : public IControl {
 private:
  MenuData *ending_data;

 public:
  explicit GLEControlSelectDown(MenuData *input_ending_data)
      : IControl("GLEControlSelectUp") {
    ending_data = input_ending_data;
  }
  ~GLEControlSelectDown() override = default;

  void execute() override {
    if (ending_data->get_highlighted() < ending_data->get_count_choices()) {
      ending_data->set_highlighted(ending_data->get_highlighted() + 1);
    }
  }
};
