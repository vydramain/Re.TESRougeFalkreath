//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MLCONTROLEMPTY_H
#define RE_TESROUGEFALKREATH_MLCONTROLEMPTY_H

#include "IMLControl.h"

class MLControlEmpty : public IMLControl {
public:
    explicit MLControlEmpty() : IMLControl("MLControlEmpty") {}

    IControl* get_last_control() {
        return nullptr;
    }
    void execute() {}
};

#endif //RE_TESROUGEFALKREATH_MLCONTROLEMPTY_H
