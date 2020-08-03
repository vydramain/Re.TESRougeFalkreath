
#include <ecs/entities/races_entities/beastfolk_race/Khadjiit.h>
#include <ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControlPlayerInteract.h>
#include <ecs/systems/scenes_system/MainMenuScene.h>
#include <ecs/systems/scenes_system/main_loop_scene/MainLoopScene.h>

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
  auto *creatures = new Creatures(0);
  auto *races = new Races(0);
  races->put_player(new Khadjiit("pl", 15, 2));
  auto *items = new Items(0);

  auto *state = new MainLoopScene("test_map", new Map(x, y, m), races, creatures, items);
  //    auto *state = new MainMenuScene();
  state->run();
  delete state;

  return 0;
}
