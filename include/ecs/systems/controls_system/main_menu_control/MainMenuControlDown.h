//
// Created by vydra on 7/29/20.
//

#ifndef RE_TESROUGEFALKREATH_MAINMENUCONTROLDOWN_H
#define RE_TESROUGEFALKREATH_MAINMENUCONTROLDOWN_H

#include <ecs/systems/controls_system/IControl.h>

class MainMenuControlDown : public IControl {
public:
    MainMenuControlDown(main_menu_state *input_state) : Control(input_state) {}
    ~MainMenuControlDown() {
        state = nullptr;
    }

    void execute() {
        state.highlighted_down();
    }
};

#endif //RE_TESROUGEFALKREATH_MAINMENUCONTROLDOWN_H
