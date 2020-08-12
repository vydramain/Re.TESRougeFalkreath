//
// Created by vydra on 8/12/20.
//

#include "core/systems/render_system/RenderSystem.h"

RenderSystem::RenderSystem() {
  SCREENMODE_X = 100;
  SCREENMODE_Y = 40;

  terminal_open();
  terminal_set("window: title='re.TESRougeFalkreath', size=100x40, fullscreen=true;");
  terminal_layer(0);
  terminal_clear();
  terminal_refresh();
}

RenderSystem::~RenderSystem() {
  if (!render_entity) {
    delete render_entity;
  }
  terminal_close();
}

void RenderSystem::set_main_menu_render(const char *input_question, const char **input_choices,
                                        unsigned int input_count_choices, unsigned int *input_highlighted_choice) {
  if (!render_entity) {
    delete render_entity;
  }
  render_entity = new MainMenuRender(SCREENMODE_X, SCREENMODE_Y, input_question, input_choices, input_count_choices,
                              input_highlighted_choice);
}

void RenderSystem::set_pseudo_game_loop_render(LocationSystem *input_location_system) {
  if (!render_entity) {
    delete render_entity;
  }
  render_entity = new PseudoGameLoopRender(SCREENMODE_X, SCREENMODE_Y, input_location_system);
}
void RenderSystem::render() {
  render_entity->render();
}
