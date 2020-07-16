
#include <iostream>
#include "gsm/game_states/global_game_states/main_menu_state.h"
#include "gsm/game_states/global_game_states/game_loop_state.h"

#include "ecs/entities/creatures_entities/creatures_entity.h"


int main() {
    char **m = new char *[200];
    for (int i = 0; i < 200; i++) {
        m[i] = new char[300];
    }
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 300; j++) {
            m[i][j] = '.';
        }
    }

    auto *state = new game_loop_state("test_map",
                                      new area_entity(200, 300, m),
                                      new creature_entity("player", 199, 290));
    state->run();
    delete state;

    return 0;
}