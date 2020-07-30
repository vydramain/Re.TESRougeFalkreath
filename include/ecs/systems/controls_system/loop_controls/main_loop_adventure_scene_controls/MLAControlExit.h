//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_MLACONTROLEXIT_H
#define RE_TESROUGEFALKREATH_MLACONTROLEXIT_H

#include <ecs/systems/controls_system/IControl.h>

class MLAControlExit : public IControl {
public:
    MLAControlExit() : IControl("MLAControlExit") {}

    void execute() {}

};

#endif //RE_TESROUGEFALKREATH_MLACONTROLEXIT_H
