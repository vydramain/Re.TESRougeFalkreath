//
// Created by vydra on 14.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H
#define RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H

#include "gsm/game_states/global_game_states/global_game_state.h"
#include "ecs/components/controls_component/input_key.h"
#include "ecs/components/render_component/game_loop_render.h"
#include "ecs/entities/creatures/creature.h"

class game_loop_state : public global_game_state {
private:
    input_key *input = nullptr;
    game_loop_render *render = nullptr;


public:
    explicit game_loop_state();
    ~game_loop_state();

    void run() override;

};

#endif //RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H
