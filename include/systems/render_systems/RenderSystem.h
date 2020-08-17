//
// Created by vydra on 8/11/20.
//

#pragma once

#include "./BearLibTerminal.h"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "entities/render_entities/game_loop_render/PseudoGameLoopRender.h"
#include "entities/render_entities/main_menu_render/MainMenuRender.h"
#include "systems/location_systems/LocationSystem.h"
#include "systems/render_systems/IRenderSystem.h"

/*
 * Class response all terminal options.
 * It means that resolution, window's title, fullscreen mode, graphic's type is under control by this class.
 */
class RenderSystem : public IRenderSystem {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  IRender* render_entity = nullptr;

 public:
  explicit RenderSystem();
  ~RenderSystem() override;

  void set_pseudo_game_loop_render(ILocationSystem* input_location_system) override;
  void set_main_menu_render(const char* input_question, const char** input_choices, unsigned input_count_choices,
                            unsigned* input_highlighted_choice) override;

  void render() override;
};
