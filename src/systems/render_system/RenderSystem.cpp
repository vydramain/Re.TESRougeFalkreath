//
// Created by vydra on 8/12/20.
//

#include "systems/render_systems/RenderSystem.h"

RenderSystem::RenderSystem() {
  SCREENMODE_X = 100;
  SCREENMODE_Y = 40;
  render_entity = nullptr;

  terminal_open();
  terminal_set("window: title='re.TESRougeFalkreath', size=100x40, fullscreen=true;");
  terminal_layer(0);
  terminal_clear();
  terminal_refresh();
}

RenderSystem::~RenderSystem() {
  delete render_entity;
  terminal_close();
}

void RenderSystem::set_main_menu_render(const char *input_question, const char **input_choices,
                                        unsigned int input_count_choices, unsigned int *input_highlighted_choice) {
  printf("%s", "[RenderSystem] - Setting up main menu render\n");
  delete render_entity;
  render_entity = new MainMenuRender(SCREENMODE_X, SCREENMODE_Y, input_question, input_choices, input_count_choices,
                                     input_highlighted_choice);
}

void RenderSystem::set_pseudo_game_loop_render(ILocationSystem *input_location_system) {
  printf("%s", "[RenderSystem] - Setting up pseudo game loop render\n");
  delete render_entity;
  render_entity = new PseudoGameLoopRender(SCREENMODE_X, SCREENMODE_Y, input_location_system);
}
void RenderSystem::render() {
  render_entity->render();
}
