//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERLEFT_H
#define RE_TESROUGEFALKREATH_PLAYERLEFT_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerLeft : public IControl {
private:
    Creature *player;

public:
    explicit MLAControlPlayerLeft (Creature* input_player) : player(input_player), IControl("MLAControlPlayerLeft") {}

    void execute() override {
        player->go_left();
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERLEFT_H
