//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class GControlExit : public IControl {
 public:
  explicit GControlExit() : IControl("GControlExit") {}
  ~GControlExit() override = default;

  void execute() override {}
};
