//
// Created by vydra on 8/12/20.
//

#include "entities/render_entities/game_loop_render/GameLoopRender.h"

#include <string>

void GameLoopRender::set_pseudo_mode() {
  world = new GameLoopPseudoRender(data);
}

void GameLoopRender::set_grafic_mode() {
  world = new GameLoopGraficRender(data);
}

GameLoopRender::GameLoopRender(unsigned int input_screen_x, unsigned int input_screen_y,
                               IWorldSystem *input_world_system, bool is_pseudo,
                               ParameterQueryDataSet *input_ending_data)
    : IRender() {
  data = new RenderConfigurationData(input_screen_x, input_screen_y, input_world_system);
  if (is_pseudo) {
    set_pseudo_mode();
  } else {
    set_grafic_mode();
  }
  hud = new GameLoopHUDRender(data, input_ending_data);
  ending = new GameLoopEndingRender(data, input_ending_data->get_data(new std::string("statistic_data")));
}

GameLoopRender::~GameLoopRender() {
  delete world;
  delete hud;
  delete ending;
}

void GameLoopRender::render_world() {
  if (!world) {
    terminal_layer(20);
    terminal_print(0, 0, "World render not set up");
    return;
  }
  world->render();
}

void GameLoopRender::render_hud() {
  hud->render();
}

void GameLoopRender::render_end() {
  ending->render();
}

void GameLoopRender::render() {
  CleanerRender::clean_all();

  data->update_camera_position_x();
  data->update_camera_position_y();

  if (data->get_world_system()->get_ending_game()) {
    render_end();
  } else {
    render_world();
    render_hud();
  }

  terminal_refresh();
}
