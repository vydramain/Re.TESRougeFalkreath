//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H
#define RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H

#include <string>
#include <ecs/systems/controls_system/IControl.h>

class IScene {
private:
    const char* name;
public:
    explicit IScene(const char* input_name): name(input_name) {}
    virtual void run() = 0;

    const char* getSceneName() {
        return name;
    }
};

#endif //RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H
