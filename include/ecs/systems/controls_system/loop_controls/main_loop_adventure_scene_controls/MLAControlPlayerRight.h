//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERRIGHT_H
#define RE_TESROUGEFALKREATH_PLAYERRIGHT_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerRight : public IControl {
private:
    const Location *location;

public:
    explicit MLAControlPlayerRight (const Location* input_location) : location(input_location), IControl("MLAControlPlayerRight") {}

    void execute() override {
        location->get_current_creatures()->get_creature(0)->go_right(location->get_size_x());
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERRIGHT_H
