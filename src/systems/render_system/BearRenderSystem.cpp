//
// Created by vydra on 8/12/20.
//

#include "systems/render_systems/BearRenderSystem.h"

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

void BearRenderSystem::set_main_menu_data(const char *input_menu_title, const char **input_menu_choices,
                                          unsigned int input_count_menu_choices, unsigned int *input_menu_highlighted) {
  is_menu = true;
  menu_title = input_menu_title;
  menu_choices = input_menu_choices;
  count_menu_choices = input_count_menu_choices;
  menu_highlighted = input_menu_highlighted;
}

void BearRenderSystem::set_game_loop_data(LocationSystem *input_location_system,
                                          unsigned int *input_ending_highlighted) {
  is_game_loop = true;
  location_system = input_location_system;
  ending_highlighted = input_ending_highlighted;
}

void BearRenderSystem::set_main_menu_render() {
  printf("%s", "[RenderSystem] - Setting up main menu render\n");
  delete render_entity;
  if(is_menu) {
    render_entity =
        new MainMenuRender(SCREENMODE_X, SCREENMODE_Y, menu_title, menu_choices, count_menu_choices, menu_highlighted);
  }
}

void BearRenderSystem::set_pseudo_game_loop_render() {
  printf("%s", "[RenderSystem] - Setting up pseudo game loop render\n");
  delete render_entity;
  if(is_game_loop) {
    render_entity = new PseudoGameLoopRender(SCREENMODE_X, SCREENMODE_Y, location_system, ending_highlighted);
  }
}

void BearRenderSystem::render() {
  if(render_entity) {
    render_entity->render();
  } else {
    terminal_clear();
    terminal_print(0, 0, "Render is not set up");
    terminal_refresh();
  }
}
