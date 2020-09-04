//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class SEControlSelectExit : public IControl {
 public:
  explicit SEControlSelectExit() : IControl("SEControlSelectExit") {}
  ~SEControlSelectExit() override = default;

  void execute() override {}
};
