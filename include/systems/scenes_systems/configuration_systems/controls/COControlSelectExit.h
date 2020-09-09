//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class COControlSelectExit : public IControl {
 public:
  explicit COControlSelectExit() : IControl("COControlSelectExit") {}
  ~COControlSelectExit() override = default;

  void execute() override {}
};
