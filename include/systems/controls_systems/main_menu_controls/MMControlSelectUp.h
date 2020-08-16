//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class MMControlSelectUp : public IControl {
 private:
  const unsigned count_choices;
  unsigned *highlighted;

 public:
  explicit MMControlSelectUp(const unsigned input_count, unsigned *input_highlighted)
      : IControl("MMControlSelectUp"), count_choices(input_count) {
    highlighted = input_highlighted;
  }
  ~MMControlSelectUp() override = default;

  void execute() override {
    if (*highlighted > 1) {
      *highlighted -= 1;
    }
  }
};
