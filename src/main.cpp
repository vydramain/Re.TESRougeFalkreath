
#include <iostream>
#include "gsm/game_states/global_game_states/main_menu_state.h"
#include "gsm/game_states/global_game_states/game_loop_state.h"

int main() {
    auto *state = new game_loop_state();
    state->run();
    delete state;

    return 0;
}