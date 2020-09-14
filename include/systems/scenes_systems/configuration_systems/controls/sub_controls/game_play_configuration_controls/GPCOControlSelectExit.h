//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class GPCOControlSelectExit : public IControl {
 public:
  explicit GPCOControlSelectExit() : IControl("GPCOControlSelectExit") {}
  ~GPCOControlSelectExit() override = default;

  void execute() override {}
};
