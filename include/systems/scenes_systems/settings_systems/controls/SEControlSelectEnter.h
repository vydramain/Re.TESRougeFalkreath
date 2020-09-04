//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class SEControlSelectEnter : public IControl {
 public:
  explicit SEControlSelectEnter() : IControl("SEControlSelectEnter") {}
  ~SEControlSelectEnter() override = default;

  void execute() override {}
};
