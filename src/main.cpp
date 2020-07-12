
#include "gsm/game_states/global_game_states/global_game_state.h"
#include "gsm/game_states/global_game_states/main_menu_state.h"

int main() {
    auto* state = new main_menu_state();
    state->update();
    delete state;

    return 0;
}