//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class COControlSelectEmpty : public IControl {
 public:
  explicit COControlSelectEmpty() : IControl("COControlSelectEmpty") {}
  ~COControlSelectEmpty() override = default;

  void execute() override {}
};
