//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MLSCONTROLEMPTY_H
#define RE_TESROUGEFALKREATH_MLSCONTROLEMPTY_H

#include <ecs/systems/controls_system/IControl.h>

class MLAControlEmpty : public IControl {
public:
    explicit MLAControlEmpty() : IControl("MLAControlEmpty") {}
    void execute() override {}

};

#endif //RE_TESROUGEFALKREATH_MLSCONTROLEMPTY_H
