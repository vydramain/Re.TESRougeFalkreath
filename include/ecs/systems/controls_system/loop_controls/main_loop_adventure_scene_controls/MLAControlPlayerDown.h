//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERDOWN_H
#define RE_TESROUGEFALKREATH_PLAYERDOWN_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerDown : public IControl {
private:
    const Location *location;

public:
    explicit MLAControlPlayerDown(const Location* input_location) : location(input_location), IControl("MLAControlPlayerDown") {}

    void execute() override {
        location->get_current_creatures()->get_creature(0)->go_down(location->get_size_y());
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERDOWN_H
