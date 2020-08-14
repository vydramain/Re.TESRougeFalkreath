//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Wall.h"
#include "core/entities/location_enities/items_entities/Coin.h"
#include "core/entities/location_enities/sentients_entities/beastfolks/Khadjiit.h"
#include "core/entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "core/systems/controls_system/IControl.h"
#include "core/systems/location_system/sub_systems/entities_system/ItemsSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "core/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

class GControlNewGame : public IControl {
 private:
  RenderSystem *render_system;
  unsigned *highlighted;

 public:
  explicit GControlNewGame(RenderSystem *input_system, unsigned *input_pointer)
      : IControl("GlobalControlNewGame"), render_system(input_system), highlighted(input_pointer) {}
  ~GControlNewGame() override = default;

  void execute() override {
    *highlighted = 0;
    unsigned x = 100;
    unsigned y = 110;

    auto *entities = new LocationsEntitiesSystem();
    entities->put_player(new Khadjiit("player", 'K', 0xffEEEEEE, 5, 2));
    entities->put_magwehr(new Magwehr("Dragon", 'D', 0xeeFF2233, 25, 5));
    entities->put_item(new Coin(3, 2));
    entities->put_item(new Coin(4, 7));
    entities->put_item(new Coin(13, 12));
    entities->put_item(new Coin(33, 20));
    entities->put_item(new Coin(43, 42));
    entities->put_ambient(new Wall(15, 15));

    auto *main_scene = new GameLoopScene(render_system, x, y, entities);

    main_scene->run();
    delete main_scene;
  }
};
