//
// Created by vydra on 7/29/20.
//

#ifndef RE_TESROUGEFALKREATH_MAINMENUCONTROL_H
#define RE_TESROUGEFALKREATH_MAINMENUCONTROL_H

class IControl {
protected:
    interface_game_state *state;

public:
    IControl(interface_game_state *input_state) : state(inptu_state) {}
    virtual ~IControl() = 0;

    virtual void execute() = 0;

};

#endif //RE_TESROUGEFALKREATH_MAINMENUCONTROL_H
