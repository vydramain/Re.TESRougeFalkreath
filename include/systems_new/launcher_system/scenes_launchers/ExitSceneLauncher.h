//
// Created by vydra on 7/31/20.
//

#pragma once

#include "adds/log_systems/PseudoLogSystem.hpp"
#include "systems/controls_systems/IControl.h"

class ExitSceneLauncher : public IControl {
 public:
  explicit ExitSceneLauncher();
  ~ExitSceneLauncher() override;

  void execute() override;
};
