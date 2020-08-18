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
class BearRenderSystem : public IRenderSystem {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  IRender *render_entity = nullptr;

  bool is_menu = false;
  const char *menu_title = nullptr;
  const char **menu_choices = nullptr;
  unsigned count_menu_choices = 0;
  unsigned *menu_highlighted = nullptr;

  bool is_game_loop = false;
  LocationSystem *location_system = nullptr;
  unsigned *ending_highlighted = nullptr;

 public:
  explicit BearRenderSystem();
  ~BearRenderSystem() override;

  void set_main_menu_data(const char *input_menu_title, const char **input_menu_choices,
                          unsigned input_count_menu_choices, unsigned *input_menu_highlighted);
  void set_game_loop_data(LocationSystem *input_location_system, unsigned *input_highlighted);

  void set_pseudo_game_loop_render() override;
  void set_main_menu_render() override;

  void render() override;
};
