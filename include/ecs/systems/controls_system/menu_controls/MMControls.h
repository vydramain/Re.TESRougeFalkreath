//
// Created by vydra on 7/31/20.
//

#ifndef RE_TESROUGEFALKREATH_MMCONTROLS_H
#define RE_TESROUGEFALKREATH_MMCONTROLS_H

#include <ecs/systems/controls_system/IControl.h>
#include "MMControlMap.h"

class MMControls {
private:
    MMControlMap *control_map;

public:
    explicit MMControls(const unsigned input_count, unsigned &input_highlighted) : control_map(new MMControlMap(input_count, input_highlighted)) {}
    ~MMControls() = default;

    IControl* update() {
        auto key = terminal_read();
        return control_map->get_control(key);
    }
};

#endif //RE_TESROUGEFALKREATH_MMCONTROLS_H
