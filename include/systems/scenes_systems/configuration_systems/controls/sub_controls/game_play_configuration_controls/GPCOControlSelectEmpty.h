//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class GPCOControlSelectEmpty : public IControl {
 public:
  explicit GPCOControlSelectEmpty() : IControl("GPCOControlSelectEmpty") {}
  ~GPCOControlSelectEmpty() override = default;

  void execute() override {}
};
