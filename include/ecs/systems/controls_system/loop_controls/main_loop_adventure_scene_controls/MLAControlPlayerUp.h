//
// Created by vydra on 7/30/20.
//

#ifndef RE_TESROUGEFALKREATH_GOUP_H
#define RE_TESROUGEFALKREATH_GOUP_H

#include <ecs/systems/controls_system/IControl.h>
#include <ecs/entities/creatures_entities/Creature.h>

class MLAControlPlayerUp : public IControl {
private:
    Creature *player;

public:
    explicit MLAControlPlayerUp(Creature* input_player) : player(input_player), IControl("MLAControlPlayerUp") {}

    void execute() override {
        player->go_up();
    }

};

#endif //RE_TESROUGEFALKREATH_GOUP_H
