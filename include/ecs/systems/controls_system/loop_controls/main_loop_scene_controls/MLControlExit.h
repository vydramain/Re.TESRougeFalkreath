//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MLSCONTROLCLOSE_H
#define RE_TESROUGEFALKREATH_MLSCONTROLCLOSE_H

#include "IMLControl.h"

class MLControlExit : public IMLControl {
private:

public:
    explicit MLControlExit() : IMLControl("MLControlExit") {}

    IControl *get_last_control() {
        return nullptr;
    }

    void execute() override {}

};

#endif //RE_TESROUGEFALKREATH_MLSCONTROLCLOSE_H
