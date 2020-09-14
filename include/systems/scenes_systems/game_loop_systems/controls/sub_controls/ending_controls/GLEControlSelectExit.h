//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class GLEControlSelectExit : public IControl {
 public:
  explicit GLEControlSelectExit() : IControl("GLEControlSelectExit") {}
  ~GLEControlSelectExit() override = default;

  void execute() override {}
};
