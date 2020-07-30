//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_MLASCONTROLMAP_H
#define RE_TESROUGEFALKREATH_MLASCONTROLMAP_H

#include <map>
#include <BearLibTerminal.h>
#include "MLASControlPlayerDown.h"
#include "MLASControlPlayerLeft.h"
#include "MLASControlPlayerRight.h"
#include "MLASControlPlayerUp.h"
#include "MLASControlExit.h"
#include "MLASControlEmpty.h"

class MLASControlMap {
private:
    MLASControlExit *control_exit = new MLASControlExit();
    MLASControlEmpty *control_empty = new MLASControlEmpty();
    MLASControlPlayerDown *control_player_down;
    MLASControlPlayerLeft *control_player_left;
    MLASControlPlayerRight *control_player_right;
    MLASControlPlayerUp *control_player_up;

    std::map<int, IControl *> mlas_map;
    std::map<int, IControl *>::iterator mlas_iterator;

public:
    explicit MLASControlMap(Creature *input_player) {
        control_player_down = new MLASControlPlayerDown(input_player);
        control_player_left = new MLASControlPlayerLeft(input_player);
        control_player_right = new MLASControlPlayerRight(input_player);
        control_player_up = new MLASControlPlayerUp(input_player);

        mlas_map[TK_CLOSE] = control_exit;
        mlas_map[TK_ESCAPE] = control_exit;
        mlas_map[TK_DOWN] = control_player_down;
        mlas_map[TK_LEFT] = control_player_left;
        mlas_map[TK_RIGHT] = control_player_right;
        mlas_map[TK_UP] = control_player_up;

        mlas_iterator = mlas_map.begin();
    }

    ~MLASControlMap() {
        delete control_exit;
        delete control_empty;
        delete control_player_down;
        delete control_player_left;
        delete control_player_right;
        delete control_player_up;
    }

    IControl *get_control(TERMINAL_API int input_key) {
        mlas_iterator = mlas_map.find(input_key);
        if (mlas_iterator == mlas_map.end()) {
            return control_empty;
        }
        return mlas_iterator->second;
    }
};

#endif //RE_TESROUGEFALKREATH_MLASCONTROLMAP_H
