//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_GOUP_H
#define RE_TESROUGEFALKREATH_GOUP_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLASControlPlayerUp : public IControl {
private:
    Creature *player;

public:
    explicit MLASControlPlayerUp(Creature* input_player) : player(input_player), IControl("MLASControlPlayerUp") {}

    void execute() override {
        player->go_up();
    }

};

#endif //RE_TESROUGEFALKREATH_GOUP_H
