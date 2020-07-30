//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERDOWN_H
#define RE_TESROUGEFALKREATH_PLAYERDOWN_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLASControlPlayerDown : public IControl {
private:
    Creature *player;

public:
    explicit MLASControlPlayerDown(Creature* input_player) : player(input_player), IControl("MLASControlPlayerDown") {}

    void execute() override {
        player->go_down();
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERDOWN_H
