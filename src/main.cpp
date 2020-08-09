
#include <ecs/entities/location_enities/sentients_entities/beastfolks/Khadjiit.h>
#include <ecs/entities/scenes_entities/main_scenes/main_loop_scene/MainLoopScene.h>
#include <ecs/entities/scenes_entities/main_scenes/main_menu_scene/MainMenuScene.h>
#include <ecs/systems/controls_system/loop_controls/main_loop_adventure_scene_controls/MLAControlPlayerInteract.h>

#include <core/components/sub_components/SubPseudoRendering.hpp>

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
  races->put_player(new Khadjiit("pl", 5, 2));
  auto *items = new Items(4);
  items->put_item(new Item("Coin", false, 3, 2));
  items->put_item(new Item("Coin", false, 30, 20));
  items->put_item(new Item("Coin", false, 13, 12));
  items->put_item(new Item("Coin", false, 33, 22));
  items->put_item(new Item("Coin", false, 53, 42));

  auto *state = new MainLoopScene("test_map", new Area("test", x, y, m), races, creatures, items);
  //      auto *state = new MainMenuScene();
  state->run();
  delete state;

  return 0;
}
