//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class MMControlSelectEmpty : public IControl {
 public:
  explicit MMControlSelectEmpty() : IControl("MMControlSelectEmpty") {}
  ~MMControlSelectEmpty() override = default;

  void execute() override {}
};