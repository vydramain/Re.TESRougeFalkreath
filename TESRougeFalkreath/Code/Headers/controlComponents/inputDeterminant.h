//
// Created by vydra on 8/19/19.
//

#ifndef TESROUGEFALKREATH_INPUTDETERMINANT_H
#define TESROUGEFALKREATH_INPUTDETERMINANT_H

#include "controlComponents/inputCommand.h"
#include "controlComponents/inputKey.h"

class inputDeterminant {
 private:
  bool conditionPlayerConfirm_;
  bool conditionPlayerAct_;
  bool conditionPlayerDialog_;
  bool conditionPlayerInventory_;

 public:
  explicit inputDeterminant();
  ~inputDeterminant();

  inputCommand_ determineInputKey(inputKey *INPUT);
};

#endif  // TESROUGEFALKREATH_INPUTDETERMINANT_H
