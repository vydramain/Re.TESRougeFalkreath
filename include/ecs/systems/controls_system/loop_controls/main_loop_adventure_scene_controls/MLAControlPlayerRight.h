//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_PLAYERRIGHT_H
#define RE_TESROUGEFALKREATH_PLAYERRIGHT_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerRight : public IControl {
private:
    Creature *player;

public:
    explicit MLAControlPlayerRight (Creature* input_player) : player(input_player), IControl("MLAControlPlayerRight") {}

    void execute() override {
        player->go_right();
    }

};

#endif //RE_TESROUGEFALKREATH_PLAYERRIGHT_H
