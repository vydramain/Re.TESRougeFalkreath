//
// Created by vydra on 8/19/19.
//

#include "controlComponents/inputDeterminant.h"

inputDeterminant::inputDeterminant() {
  conditionPlayerConfirm_ = false;
  conditionPlayerAct_ = false;
  conditionPlayerDialog_ = false;
  conditionPlayerInventory_ = false;
}

inputDeterminant::~inputDeterminant() {}

inputCommand_ inputDeterminant::determineInputKey(inputKey* INPUT) {
  inputCommand_ container;
  if (INPUT->IsUp()) {
    container.moveInCommand(1);  // вверх

  } else {
    if (INPUT->IsDown()) {
      container.moveInCommand(2);  // вниз

    } else {
      if (INPUT->IsLeft()) {
        container.moveInCommand(3);  // влево
      } else {
        if (INPUT->IsRight()) {
          container.moveInCommand(4);  // вправо
        }
      }
    }
  }

  if (conditionPlayerAct_) {
    if (INPUT->IsEnter()) {
      conditionPlayerAct_ = false;
      container.actInCommand(1);  // подтверждение действия
    }
  } else {
    if (conditionPlayerConfirm_) {
      unsigned act;
      container.moveOutCommand(act);
      if (act != 0) {
        conditionPlayerConfirm_ = false;
      }
    } else {
      if (conditionPlayerDialog_) {
        // unsigned act;
        // container.moveOutCommand(act);
        // if (act != 0) {
        //   conditionPlayerConfirm_ = false;
        // }
      } else {
        if (conditionPlayerInventory_) {
          // if (INPUT->IsButtonI()) {
          //   conditionPlayerInventory_ = false;
          //   container.actInCommand(0);
          // }
        }
      }
    }
  }

  if (INPUT->IsButtonE()) {
    conditionPlayerAct_ = true;
    container.actInCommand(5);  // действие с объектом
  } else {
    if (INPUT->IsButtonQ()) {
      conditionPlayerConfirm_ = true;
      container.actInCommand(6);  // Осмотр предмета
    } else {
      if (INPUT->IsButtonD()) {
        // conditionPlayerDialog_ = true;
        // container.actInCommand(3);
      } else {
        if (INPUT->IsButtonI()) {
          // conditionPlayerInventory_ = true;
          // container.actInCommand(4);
        }
      }
    }
  }

  return container;
}