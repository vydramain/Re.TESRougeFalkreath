//
// Created by vydra on 8/12/20.
//

#include "systems_new/render_systems/BearRenderSystem.h"

BearRenderSystem::BearRenderSystem() {
  SCREENMODE_X = 100;
  SCREENMODE_Y = 40;
  render_entity = nullptr;

  terminal_open();
  terminal_set("window: title='re.TESRougeFalkreath', size=100x40, fullscreen=true;");
  terminal_layer(0);
  terminal_clear();
  terminal_refresh();
}

BearRenderSystem::~BearRenderSystem() {
  delete render_entity;
  terminal_close();
}

void BearRenderSystem::set_main_menu_data(ParameterQueryData *input_menu_data) {
  is_menu = true;
  menu_data = input_menu_data;
}

void BearRenderSystem::set_score_list_data(StringsListData *input_score_list_data) {
  is_score_list = true;
  score_list_data = input_score_list_data;
}

void BearRenderSystem::set_game_loop_data(ILocationSystem *input_location_system,
                                          ParameterQueryData *input_ending_data) {
  is_game_loop = true;
  location_system = input_location_system;
  ending_data = input_ending_data;
}

void BearRenderSystem::set_main_menu_render() {
  printf("%s", "[RenderSystem] - Setting up main menu render\n");
  delete render_entity;
  if (is_menu) {
    render_entity = new MainMenuRender(SCREENMODE_X, SCREENMODE_Y, menu_data);
  }
}

void BearRenderSystem::set_score_list_render() {
  printf("%s", "[RenderSystem] - Setting up score list render\n");
  delete render_entity;
  if (is_score_list) {
    render_entity = new StatisticsRender(SCREENMODE_X, SCREENMODE_Y, score_list_data);
  }
}

void BearRenderSystem::set_pseudo_game_loop_render() {
  printf("%s", "[RenderSystem] - Setting up pseudo game loop render\n");
  delete render_entity;
  if (is_game_loop) {
    render_entity = new PseudoGameLoopRender(SCREENMODE_X, SCREENMODE_Y, location_system, ending_data);
  }
}

void BearRenderSystem::render() {
  if (render_entity) {
    render_entity->render();
  } else {
    terminal_clear();
    terminal_print(0, 0, "Render is not set up");
    terminal_refresh();
  }
}
