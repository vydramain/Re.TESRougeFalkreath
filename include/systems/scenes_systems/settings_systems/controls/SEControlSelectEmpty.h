//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class SEControlSelectEmpty : public IControl {
 public:
  explicit SEControlSelectEmpty() : IControl("SEControlSelectEmpty") {}
  ~SEControlSelectEmpty() override = default;

  void execute() override {}
};
