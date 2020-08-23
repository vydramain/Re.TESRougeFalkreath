//
// Created by vydra on 7/31/20.
//

#include "systems/controls_systems/IControl.h"

class GLEControlSelectDown : public IControl {
 private:
  const unsigned count_choices;
  unsigned *highlighted;

 public:
  explicit GLEControlSelectDown(const unsigned input_count, unsigned *input_highlighted)
      : IControl("GLEControlSelectUp"), count_choices(input_count) {
    highlighted = input_highlighted;
  }
  ~GLEControlSelectDown() override = default;

  void execute() override {
    if (*highlighted < count_choices) {
      *highlighted += 1;
    }
  }
};
