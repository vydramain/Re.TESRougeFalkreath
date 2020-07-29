//
// Created by vydra on 7/29/20.
//

#ifndef RE_TESROUGEFALKREATH_MAINMENUCONTROLUP_H
#define RE_TESROUGEFALKREATH_MAINMENUCONTROLUP_H

#include <ecs/systems/controls_system/IControl.h>

class MainMenuControlUp : public IControl {
public:
    MainMenuControlUp(main_menu_state *input_state) : Control(input_state) {}
    ~MainMenuControlUp() {
        state = nullptr;
    }

    void execute() {
        state.highlighted_up();
    }
};

#endif //RE_TESROUGEFALKREATH_MAINMENUCONTROLUP_H
