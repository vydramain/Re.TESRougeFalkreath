//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MMCONTROLSELECTEXIT_H
#define RE_TESROUGEFALKREATH_MMCONTROLSELECTEXIT_H

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectExit : public IControl {
public:
    explicit MMControlSelectExit() : IControl("MMControlSelectExit") {}

    void execute() override {}
};

#endif //RE_TESROUGEFALKREATH_MMCONTROLSELECTEXIT_H
