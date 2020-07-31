//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MMCONTROLSELECTEMPTY_H
#define RE_TESROUGEFALKREATH_MMCONTROLSELECTEMPTY_H

#include <ecs/systems/controls_system/IControl.h>

class MMControlSelectEmpty : public IControl {
public:
    explicit MMControlSelectEmpty() : IControl("MMControlSelectEmpty") {}

    void execute() override {}
};

#endif //RE_TESROUGEFALKREATH_MMCONTROLSELECTEMPTY_H
