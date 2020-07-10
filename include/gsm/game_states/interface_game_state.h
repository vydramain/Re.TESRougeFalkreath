//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H
#define RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H

class interface_game_state {
public:
    virtual ~interface_game_state() = 0;

    virtual char* get_game_state() const = 0;
};

#endif //RE_TESROUGEFALKREATH_INTERFACE_GAME_STATE_H
