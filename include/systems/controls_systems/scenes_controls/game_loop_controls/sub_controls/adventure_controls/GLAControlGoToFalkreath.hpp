//
// Created by vydra on 8/25/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"

class GLAControlGoToFalkreath : public IControl {
 public:
  explicit GLAControlGoToFalkreath() : IControl("GLAControlGoToFalkreath") {}

  void execute() {}
};