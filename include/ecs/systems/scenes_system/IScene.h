//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H
#define RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H

#include <string>

class IScene {
public:
    virtual void run() = 0;
    virtual const char* get_game_state() const = 0;
};

#endif //RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H
