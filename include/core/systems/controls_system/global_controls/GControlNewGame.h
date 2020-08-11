//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/location_enities/sentients_entities/beastfolks/Khadjiit.h"
#include "core/entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "core/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/sub_systems/entities_system/ItemsSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

class GControlNewGame : public IControl {
 private:
  unsigned *highlighted;

 public:
  explicit GControlNewGame(unsigned *input_pointer) : IControl("GlobalControlNewGame"), highlighted(input_pointer) {}
  ~GControlNewGame() override = default;

  void execute() override {
    delete highlighted;
    *highlighted = 0;
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

    auto *entities = new LocationsEntitiesSystem();
    entities->put_player(new Khadjiit("pl", 5, 2));
    entities->put_item(new Item("Coin", false, 3, 2));
    entities->put_item(new Item("Coin", false, 30, 20));
    entities->put_item(new Item("Coin", false, 13, 12));
    entities->put_item(new Item("Coin", false, 33, 22));
    entities->put_item(new Item("Coin", false, 53, 42));

    auto *main_scene = new GameLoopScene("test_map", new Area("test", x, y, m),
                                         entities);

    delete highlighted;
    delete entities;
    for (unsigned i = 0; i < x; i++) {
      delete m[i];
    }
    delete[] m;

    main_scene->run();
    delete main_scene;
  }
};
