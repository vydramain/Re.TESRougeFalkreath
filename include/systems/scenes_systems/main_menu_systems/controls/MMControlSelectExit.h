//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class MMControlSelectExit : public IControl {
 public:
  explicit MMControlSelectExit() : IControl("MMControlSelectExit") {}
  ~MMControlSelectExit() override = default;

  void execute() override {}
};
