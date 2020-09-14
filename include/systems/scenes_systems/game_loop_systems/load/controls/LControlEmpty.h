//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/IControl.h"

class LControlEmpty : public IControl {
 public:
  explicit LControlEmpty() : IControl("LControlEmpty") {}
  ~LControlEmpty() override = default;

  void execute() override {}
};
