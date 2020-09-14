//
// Created by vydra on 7/31/20.
//

#pragma once

#include "systems/IControl.h"

class GCOControlSelectEmpty : public IControl {
 public:
  explicit GCOControlSelectEmpty() : IControl("GCOControlSelectEmpty") {}
  ~GCOControlSelectEmpty() override = default;

  void execute() override {}
};
