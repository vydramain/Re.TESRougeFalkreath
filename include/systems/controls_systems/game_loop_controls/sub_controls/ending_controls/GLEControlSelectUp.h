//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class GLEControlSelectUp : public IControl {
 private:
  const unsigned count_choices;
  unsigned *highlighted;

 public:
  explicit GLEControlSelectUp(const unsigned input_count, unsigned *input_highlighted)
      : IControl("GLEControlSelectUp"), count_choices(input_count) {
    highlighted = input_highlighted;
  }
  ~GLEControlSelectUp() override = default;

  void execute() override {
    if (*highlighted > 1) {
      *highlighted -= 1;
    }
  }
};
