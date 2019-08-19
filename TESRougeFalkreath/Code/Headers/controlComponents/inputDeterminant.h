//
// Created by vydra on 8/19/19.
//

#ifndef TESROUGEFALKREATH_INPUTDETERMINANT_H
#define TESROUGEFALKREATH_INPUTDETERMINANT_H

#include "controlComponents/inputKey.h"

class inputDeterminant {
 private:
  bool conditionStandby_;

  bool conditionAction_;     // - 0
  bool conditionView_;       // - 1
  bool conditionDialog_;     // - 2
  bool conditionBite_;       // - 3
  bool conditionCast_;       // - 4
  bool conditionClimb_;      // - 5
  bool conditionInventory_;  // - 6

  bool moveUp_;     // - 0
  bool moveDown_;   // - 1
  bool moveLeft_;   // - 2
  bool moveRight_;  // - 3

 public:
  explicit inputDeterminant();
  ~inputDeterminant();

  bool whatMustToDo(const inputKey *INPUT, unsigned &typeACT, unsigned &ACT);
  bool whatMustToGo(const inputKey *INPUT, unsigned &typeACT, unsigned &ACT);
};

#endif  // TESROUGEFALKREATH_INPUTDETERMINANT_H
