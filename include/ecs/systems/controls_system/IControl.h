//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_ICONTROL_H
#define RE_TESROUGEFALKREATH_ICONTROL_H

#include <BearLibTerminal.h>

class IControl {
private:
    const char* name;

public:
    explicit IControl(const char* input_name = "IControl") : name(input_name) {}

    const char* get_name() {
        return name;
    }
    virtual void execute() = 0;
};

#endif //RE_TESROUGEFALKREATH_ICONTROL_H
