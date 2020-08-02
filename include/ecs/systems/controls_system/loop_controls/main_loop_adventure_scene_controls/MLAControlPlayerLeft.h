//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERLEFT_H
#define RE_TESROUGEFALKREATH_PLAYERLEFT_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerLeft : public IControl {
private:
    const Location *location;

public:
    explicit MLAControlPlayerLeft (const Location* input_location) : location(input_location), IControl("MLAControlPlayerLeft") {}

    void execute() override {
        location->get_current_creatures()->get_creature(0)->go_left();
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERLEFT_H
