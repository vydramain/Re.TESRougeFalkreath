//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H
#define RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H

#include <string>
#include "IScene.h"

class IMainScene : public IScene {
public:
    explicit IMainScene(const char *input_name = "MainScene") : IScene(input_name) {}

    virtual void run() = 0;
    const char *get_game_state() const;
};

#endif //RE_TESROUGEFALKREATH_GLOBAL_GAME_STATE_H
