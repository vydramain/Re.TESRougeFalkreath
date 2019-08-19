//
// Created by vydra on 8/19/19.
//

#include "controlComponents/inputDeterminant.h"

inputDeterminant::inputDeterminant() {
  conditionStandby_ = true;
  conditionBite_ = false;
  conditionCast_ = false;
  conditionClimb_ = false;
  conditionInventory_ = false;
  conditionAction_ = false;
  conditionDialog_ = false;
  conditionView_ = false;

  moveUp_ = false;
  moveDown_ = false;
  moveLeft_ = false;
  moveRight_ = false;
}

inputDeterminant::~inputDeterminant() {}

bool inputDeterminant::whatMustToDo(const inputKey *INPUT, unsigned &typeACT, unsigned &ACT) {
  if (conditionStandby_) {
    if (INPUT->IsButtonE()) {
      conditionAction_ = true;
      typeACT = 2;
      ACT = 0;
    } else {
      if (INPUT->IsButtonQ()) {
        conditionView_ = true;
        typeACT = 2;
        ACT = 1;
      } else {
        if (INPUT->IsButtonD()) {
          conditionDialog_ = true;
          typeACT = 2;
          ACT = 2;
        } else {
          if (INPUT->IsButtonW()) {
            conditionBite_ = true;
            typeACT = 2;
            ACT = 3;
          } else {
            if (INPUT->IsButtonS()) {
              conditionCast_ = true;
              typeACT = 2;
              ACT = 4;
            } else {
              if (INPUT->IsButtonA()) {
                conditionClimb_ = true;
                typeACT = 2;
                ACT = 5;
              } else {
                if (INPUT->IsButtonI()) {
                  conditionInventory_ = true;
                  typeACT = 2;
                  ACT = 6;
                } else {
                  typeACT = 0;
                }
              }
            }
          }
        }
      }
    }
    return false;
  }
  return true;
}

bool inputDeterminant::whatMustToGo(const inputKey *INPUT, unsigned &typeACT, unsigned &ACT) {
  if (conditionStandby_) {
    if (INPUT->IsUp()) {
      moveUp_ = true;
      typeACT = 1;
      ACT = 0;
    } else {
      if (INPUT->IsDown()) {
        moveDown_ = true;
        typeACT = 1;
        ACT = 1;
      } else {
        if (INPUT->IsLeft()) {
          moveLeft_ = true;
          typeACT = 1;
          ACT = 2;
        } else {
          if (INPUT->IsRight()) {
            moveRight_ = true;
            typeACT = 1;
            ACT = 3;
          } else {
            typeACT = 0;
          }
        }
      }
    }
    return false;
  } else {
    if (INPUT->IsUp()) {
      moveUp_ = true;
      typeACT = 1;
      ACT = 0;
    } else {
      if (INPUT->IsDown()) {
        moveDown_ = true;
        typeACT = 1;
        ACT = 1;
      } else {
        typeACT = 0;
      }
    }
    return false;
  }
}