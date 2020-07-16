//
// Created by vydra on 14.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H
#define RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H

#include "gsm/game_states/global_game_states/global_game_state.h"
#include "ecs/components/controls_component/controls_component.h"
#include "ecs/components/render_component/game_loop_render.h"
#include "ecs/entities/creatures_entities/creatures_entity.h"
#include "ecs/entities/locations_entities/location_entity.h"



class game_loop_state : public global_game_state {
private:
    controls_component *input = nullptr;
    game_loop_render *render = nullptr;

    location_entity *location = nullptr;
    creatures_entity *creatures = nullptr;

public:
    explicit game_loop_state(char* input_area_name = nullptr, area_entity *input_area = nullptr, creature_entity *input_player = nullptr);
    ~game_loop_state();

    void run() override;

};

#endif //RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H
