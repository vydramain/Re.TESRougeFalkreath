//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/location_enities/ambient_entities/Wall.h"
#include "core/entities/location_enities/items_entities/Coin.h"
#include "core/entities/location_enities/sentients_entities/beastfolks/Khadjiit.h"
#include "core/entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "core/systems/controls_system/IControl.h"
#include "core/systems/load_system/LoadSystem.h"
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
    printf("%s", "[GControlNewGame] - Execute new game control\n");
    *highlighted = 0;
    printf("%s", "[GControlNewGame] - Launch load system\n");
    auto *load = new LoadSystem();
    //    load->load_map("../maps/Falkreath.bin");
    load->load_map("maps/Falkreath.bin");

    if (load->get_entities_system() == nullptr) {
      printf("%s", "[GControlNewGame] - Map not found\n");
      printf("%s", "[GControlNewGame] - Stop load system\n");
      delete load;
      return;
    }

    load->get_entities_system()->put_player(new Khadjiit("player", "K", 0xffEEEEEE, 45, 12));
    auto *main_scene = new GameLoopScene(render_system, load->get_location_size_x(), load->get_location_size_y(),
                                         load->get_entities_system());
    main_scene->run();
    delete main_scene;
    printf("%s", "[GControlNewGame] - Stop load system\n");
    delete load;
  }
};
