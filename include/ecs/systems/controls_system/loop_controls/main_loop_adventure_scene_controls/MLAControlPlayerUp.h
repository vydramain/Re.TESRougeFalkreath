//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_GOUP_H
#define RE_TESROUGEFALKREATH_GOUP_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerUp : public IControl {
private:
    const Location *location;

public:
    explicit MLAControlPlayerUp(const Location* input_location) : location(input_location), IControl("MLAControlPlayerUp") {}

    void execute() override {
        location->get_current_creatures()->get_creature(0)->go_up();
    }

};

#endif //RE_TESROUGEFALKREATH_GOUP_H
