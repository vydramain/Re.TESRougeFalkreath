//
// Created by vydra on 8/21/20.
//

#include "systems/scenes_systems/launcher_system/scenes_launchers/LauncherGameLoopScene.h"

LauncherGameLoopScene::LauncherGameLoopScene(IRenderSystem *input_system, unsigned int *input_pointer)
    : IControl("GlobalControlNewGame"), render_system(input_system), highlighted(input_pointer) {}

LauncherGameLoopScene::~LauncherGameLoopScene() {}

void LauncherGameLoopScene::execute() {
  PseudoLogSystem::log(get_name(), "Launch game loop scene");
  *highlighted = 0;
  PseudoLogSystem::log(get_name(), "Create the locations entities system by load system");
  auto *load = new LoadSystem("../maps/Falkreath.bin");
  load->load_map();

  if (load->get_entities_system() == nullptr) {
    PseudoLogSystem::log(get_name(), "Map not found");
    PseudoLogSystem::log(get_name(), "Stop load system");
    delete load;
    return;
  }

  load->get_entities_system()->put_player(new Khadjiit("player", "K", 0xffEEEEEE, 18, 96));
  auto *main_scene = new GameLoopScene(render_system, load->get_location_size_x(), load->get_location_size_y(),
                                       load->get_entities_system());
  main_scene->run();
  delete main_scene;
  delete load;
}
