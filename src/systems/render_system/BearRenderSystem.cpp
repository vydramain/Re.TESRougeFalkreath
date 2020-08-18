//
// Created by vydra on 8/12/20.
//

#include "systems/render_systems/BearRenderSystem.h"

BearRenderSystem::BearRenderSystem(const char* input_menu_title, const char** input_menu_choices,
                                   unsigned input_count_menu_choices, unsigned* input_highlighted_menu_choice,
                                   ILocationSystem* input_location_system, unsigned* input_ending_highlighted) {
  menu_title = input_menu_title;
  menu_choices = input_menu_choices;
  count_menu_choices = input_count_menu_choices;
  highlighted_menu_choice = input_highlighted_menu_choice;

  location_system = input_location_system;
  ending_highlighted = input_ending_highlighted;

  SCREENMODE_X = 100;
  SCREENMODE_Y = 40;

  terminal_open();
  terminal_set("window: title='re.TESRougeFalkreath', size=100x40, fullscreen=true;");
  terminal_layer(0);
  terminal_clear();
  terminal_refresh();
}

BearRenderSystem::~BearRenderSystem() {
  menu_title = nullptr;
  menu_choices = nullptr;
  highlighted_menu_choice = nullptr;

  location_system = nullptr;
  ending_highlighted = nullptr;

  delete render_entity;
  terminal_close();
}

void BearRenderSystem::set_main_menu_render() {
  printf("%s", "[BearRenderSystem] - Setting up main menu render\n");
  delete render_entity;
  render_entity = new MainMenuRender(SCREENMODE_X, SCREENMODE_Y, menu_title, menu_choices, count_menu_choices,
                                     highlighted_menu_choice);
}

void BearRenderSystem::set_pseudo_game_loop_render() {
  printf("%s", "[BearRenderSystem] - Setting up pseudo game loop render\n");
  delete render_entity;
  render_entity = new PseudoGameLoopRender(SCREENMODE_X, SCREENMODE_Y, location_system, ending_highlighted);
}
void BearRenderSystem::render() {
  render_entity->render();
}
