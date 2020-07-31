//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MMCONTROLSELECTENTER_H
#define RE_TESROUGEFALKREATH_MMCONTROLSELECTENTER_H

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectEnter : public IControl {
public:
    explicit MMControlSelectEnter() : IControl("MMControlSelectEnter") {}

    void execute() override {}
};

#endif //RE_TESROUGEFALKREATH_MMCONTROLSELECTENTER_H
