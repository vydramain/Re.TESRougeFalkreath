//
// Created by vydra on 8/9/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Wall.h"
#include "entities/location_entities/items_entities/Coin.h"
#include "entities/location_entities/sentients_entities/beastfolks/Khadjiit.h"
#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems/load_systems/LoadSystem.h"
#include "systems/location_systems/sub_systems/entities_system/ItemsSystem.h"
#include "systems/location_systems/sub_systems/entities_system/MagwehrsSystem.h"
#include "systems/location_systems/sub_systems/entities_system/SentientsSystem.h"

class GControlNewGame : public IControl {
 private:
  IRenderSystem *render_system;
  unsigned *highlighted;

 public:
  explicit GControlNewGame(IRenderSystem *input_system, unsigned *input_pointer)
      : IControl("GlobalControlNewGame"), render_system(input_system), highlighted(input_pointer) {}
  ~GControlNewGame() override = default;

  void execute() override {
    printf("%s", "[GControlNewGame] - Execute new game control\n");
    *highlighted = 0;
    printf("%s", "[GControlNewGame] - Launch load system\n");
    auto *load = new LoadSystem("../maps/Falkreath.bin");
    //    auto *load = new LoadSystem("maps/Falkreath.bin");
    load->load_map();

    if (load->get_entities_system() == nullptr) {
      printf("%s", "[GControlNewGame] - Map not found\n");
      printf("%s", "[GControlNewGame] - Stop load system\n");
      delete load;
      return;
    }

    load->get_entities_system()->put_player(new Khadjiit("player", "K", 0xffEEEEEE, 18, 96));
    auto *main_scene = new GameLoopScene(render_system, load->get_location_size_x(), load->get_location_size_y(),
                                         load->get_entities_system());
    main_scene->run();
    delete main_scene;
    printf("%s", "[GControlNewGame] - Stop load system\n");
    delete load;
  }
};
