//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class GLEControlSelectEmpty : public IControl {
 public:
  explicit GLEControlSelectEmpty() : IControl("GLEControlSelectEmpty") {}
  ~GLEControlSelectEmpty() override = default;

  void execute() override {}
};
