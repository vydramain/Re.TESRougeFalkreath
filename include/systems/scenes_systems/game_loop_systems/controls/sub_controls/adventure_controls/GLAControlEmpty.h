//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class GLAControlEmpty : public IControl {
 public:
  explicit GLAControlEmpty() : IControl("GLAControlEmpty") {}
  void execute() override {}
};
