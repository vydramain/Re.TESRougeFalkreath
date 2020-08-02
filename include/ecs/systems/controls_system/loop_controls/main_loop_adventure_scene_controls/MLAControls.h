//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_MLACONTROLS_H
#define RE_TESROUGEFALKREATH_MLACONTROLS_H

#include <BearLibTerminal.h>
#include "MLAControlMap.h"

class MLAControls {
private:
    MLAControlMap *control_map;

public:
    explicit MLAControls(Location *input_location) : control_map(new MLAControlMap(input_location)) {}
    ~MLAControls() = default;

    IControl* update() {
        auto key = terminal_read();
        return control_map->get_control(key);
    }
};

#endif //RE_TESROUGEFALKREATH_MLACONTROLS_H
