//
// Created by vydra on 8/12/20.
//

#include "systems/render_systems/BearRenderSystem.h"

#include <string>

void BearRenderSystem::reset_render() {
  terminal_close();
}

void BearRenderSystem::set_resolution_1280x720() {
  SCREENMODE_X = 64;
  SCREENMODE_Y = 20;
  render_entity = nullptr;

  terminal_open();
  terminal_set(
      "window: title='re.TESRougeFalkreath', size=64x20, fullscreen=true;"
      " font: ../fonts/Determenation2.ttf, size='20x36'");
  terminal_clear();
  terminal_refresh();
}

void BearRenderSystem::set_resolution_1920x1080() {
  SCREENMODE_X = 96;
  SCREENMODE_Y = 30;
  render_entity = nullptr;

  terminal_open();
  terminal_set(
      "window: title='re.TESRougeFalkreath', size=96x30, fullscreen=true;"
      " font: ../fonts/Determenation2.ttf, size='20x36'");
  terminal_clear();
  terminal_refresh();
}

BearRenderSystem::BearRenderSystem(const SubResolution *input_resolution) {
  if (input_resolution->get_current_resolution() == AbsResolution::R_1280x720) {
    set_resolution_1280x720();
  }
  if (input_resolution->get_current_resolution() == AbsResolution::R_1920x1080) {
    set_resolution_1920x1080();
  }
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

void BearRenderSystem::set_settings_data(ParameterQueryData *input_settings_data) {
  is_settings_list = true;
  settings_data = input_settings_data;
}

void BearRenderSystem::set_game_loop_data(IWorldSystem *input_world_system, ParameterQueryData *input_ending_data) {
  is_game_loop = true;
  world_system = input_world_system;
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

void BearRenderSystem::set_setting_render() {
  PseudoLogSystem::log("RenderSystem", "Setting up setting render");
  delete render_entity;
  if (is_settings_list) {
    render_entity = new SettingsRender(SCREENMODE_X, SCREENMODE_Y, settings_data);
  }
}

void BearRenderSystem::set_pseudo_game_loop_render() {
  printf("%s", "[RenderSystem] - Setting up pseudo game loop render\n");
  delete render_entity;
  if (is_game_loop) {
    render_entity = new GameLoopRender(SCREENMODE_X, SCREENMODE_Y, world_system, ending_data);
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
