
#include <iostream>
#include "gsm/game_states/global_game_states/main_menu_state.h"
#include "gsm/game_states/global_game_states/game_loop_state.h"

#include "ecs/entities/creatures_entities/creatures_entity.h"


int main() {
    unsigned x = 70;
    unsigned y = 50;

    char **m = new char *[x];
    for (unsigned i = 0; i < x; i++) {
        m[i] = new char[y];
    }
    for (unsigned i = 0; i < x; i++) {
        for (unsigned j = 0; j < y; j++) {
            m[i][j] = '.';
        }
    }

    auto *state = new game_loop_state("test_map",
                                      new area_entity(x, y, m),
                                      new creature_entity("player", 15, 2));
    state->run();
    delete state;

    return 0;
}