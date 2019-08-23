//
// Created by vydra on 8/19/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTDETERMINANT_H_
#define TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTDETERMINANT_H_

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

#endif  // TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_INPUTDETERMINANT_H_
