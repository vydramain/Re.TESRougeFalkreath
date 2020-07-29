//
// Created by vydra on 12.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H
#define RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H

#include "ecs/systems/scenes_system/IMainScene.h"
#include "ecs/systems/render_system/main_menu_render.h"
#include "ecs/systems/controls_system/Controls.h"


class MainMenuScene : public IMainScene {
private:
    Controls *input;
    main_menu_render *render;

    unsigned highlighted = 0;

public:
    explicit MainMenuScene() : IMainScene("main_menu") {
        render = new main_menu_render();
        input = new Controls();
    }
    ~MainMenuScene() {
        delete input;
        delete render;
    }

    void run() override;
};

#endif //RE_TESROUGEFALKREATH_MAIN_MENU_STATE_H