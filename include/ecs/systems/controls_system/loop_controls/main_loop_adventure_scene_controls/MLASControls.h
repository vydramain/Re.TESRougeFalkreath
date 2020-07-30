//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_MLASCONTROLS_H
#define RE_TESROUGEFALKREATH_MLASCONTROLS_H

#include <BearLibTerminal.h>
#include "MLASControlMap.h"

class MLASControls {
private:
    MLASControlMap *control_map;

public:
    explicit MLASControls(Creature *input_player) : control_map(new MLASControlMap(input_player)) {}
    ~MLASControls() = default;

    IControl* update() {
        auto key = terminal_read();
        return control_map->get_control(key);
    }
};

#endif //RE_TESROUGEFALKREATH_MLASCONTROLS_H
