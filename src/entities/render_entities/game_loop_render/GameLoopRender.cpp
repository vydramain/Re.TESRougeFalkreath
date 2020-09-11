//
// Created by vydra on 8/12/20.
//

#include "entities/render_entities/game_loop_render/GameLoopRender.h"

GameLoopRender::GameLoopRender(unsigned int input_screen_x, unsigned int input_screen_y,
                               IWorldSystem *input_world_system, ParameterQueryData *input_ending_data)
    : IRender() {
  data = new RenderConfigurationData(input_screen_x, input_screen_y, input_world_system);
  world = new GameLoopGraficRender(data);
  hud = new GameLoopHUDRender(data);
  ending = new GameLoopEndingRender(data, input_ending_data);
}

GameLoopRender::~GameLoopRender() {
  delete world;
  delete hud;
  delete ending;
}

void GameLoopRender::render_world() {
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
