//
// Created by vydra on 14.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H
#define RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H

#include "ecs/systems/scenes_system/IMainScene.h"
#include "ecs/systems/render_system/game_loop_render.h"
#include "ecs/systems/controls_system/Controls.h"
#include "ecs/entities/creatures_entities/creatures_entity.h"
#include "ecs/entities/locations_entities/location_entity.h"



class MainLoopScene : public IMainScene {
private:
    Controls *input = nullptr;
    game_loop_render *render = nullptr;

    location_entity *location = nullptr;

public:
    explicit MainLoopScene(const char* input_area_name = nullptr, area_entity *input_area = nullptr, creature_entity *input_player = nullptr);
    ~MainLoopScene();

    void run() override;

};

#endif //RE_TESROUGEFALKREATH_GAME_LOOP_STATE_H
