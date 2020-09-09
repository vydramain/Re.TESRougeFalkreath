//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class GCOControlSelectExit : public IControl {
 public:
  explicit GCOControlSelectExit() : IControl("GCOControlSelectExit") {}
  ~GCOControlSelectExit() override = default;

  void execute() override {}
};
