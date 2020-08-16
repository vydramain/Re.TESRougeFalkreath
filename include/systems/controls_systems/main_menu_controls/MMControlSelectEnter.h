//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class MMControlSelectEnter : public IControl {
 public:
  explicit MMControlSelectEnter() : IControl("MMControlSelectEnter") {}
  ~MMControlSelectEnter() override = default;

  void execute() override {}
};
