//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_MLASCONTROLEXIT_H
#define RE_TESROUGEFALKREATH_MLASCONTROLEXIT_H

#include <ecs/systems/controls_system/IControl.h>

class MLASControlExit : public IControl {
public:
    MLASControlExit() : IControl("MLASControlExit") {}

    void execute() {}

};

#endif //RE_TESROUGEFALKREATH_MLASCONTROLEXIT_H
