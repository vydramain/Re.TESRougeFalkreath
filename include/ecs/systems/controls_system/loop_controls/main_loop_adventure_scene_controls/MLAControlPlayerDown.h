//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERDOWN_H
#define RE_TESROUGEFALKREATH_PLAYERDOWN_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerDown : public IControl {
private:
    Creature *player;

public:
    explicit MLAControlPlayerDown(Creature* input_player) : player(input_player), IControl("MLAControlPlayerDown") {}

    void execute() override {
        player->go_down();
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERDOWN_H
