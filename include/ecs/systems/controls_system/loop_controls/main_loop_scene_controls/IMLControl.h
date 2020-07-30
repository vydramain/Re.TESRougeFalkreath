//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_IMLCONTROL_H
#define RE_TESROUGEFALKREATH_IMLCONTROL_H

#include <ecs/systems/controls_system/IControl.h>

class IMLControl : public IControl {
public:
    explicit IMLControl(const char* input_name = "IMLControl") : IControl(input_name) {}

    virtual IControl *get_last_control() = 0;
    void execute() override = 0;

};

#endif //RE_TESROUGEFALKREATH_IMLCONTROL_H
