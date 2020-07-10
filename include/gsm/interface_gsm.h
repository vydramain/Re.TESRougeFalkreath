//
// Created by vydra on 10.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_INTERFACE_GSM_H
#define RE_TESROUGEFALKREATH_INTERFACE_GSM_H

#include "game_states/interface_game_state.h"

class interface_gsm {
public:
    virtual ~interface_gsm() = 0;

    /*
     * Method for creating new game state
     * returns new game state
     */
    virtual interface_game_state new_state() = 0;
};

#endif //RE_TESROUGEFALKREATH_INTERFACE_GSM_H
