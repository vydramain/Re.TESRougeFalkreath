
#include <iostream>
#include <ecs/systems/scenes_system/MainMenuScene.h>
#include <ecs/systems/scenes_system/MainLoopScene.h>

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

    auto *state = new MainLoopScene("test_map",
                                      new area_entity(x, y, m),
                                      new creature_entity("player", 15, 2));
//    auto *state = new MainMenuScene();
    state->run();
    delete state;

    return 0;
}