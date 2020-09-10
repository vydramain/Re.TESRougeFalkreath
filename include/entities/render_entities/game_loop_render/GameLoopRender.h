//
// Created by vydra on 8/12/20.
//

#pragma once

#include <cstring>

#include "./BearLibTerminal.h"
#include "entities/data_entities/RenderConfigurationData.hpp"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "entities/render_entities/game_loop_render/sub_renders/GameLoopEndingRender.hpp"
#include "entities/render_entities/game_loop_render/sub_renders/GameLoopHUDRender.hpp"
#include "entities/render_entities/game_loop_render/sub_renders/GameLoopPseudoRender.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/SentientsSystem.h"

class GameLoopRender : public IRender {
 private:
  RenderConfigurationData *data = nullptr;

  IRender *world = nullptr;
  GameLoopHUDRender *hud = nullptr;
  GameLoopEndingRender *ending = nullptr;

 public:
  explicit GameLoopRender(unsigned input_screen_x, unsigned input_screen_y, IWorldSystem *input_world_system,
                          ParameterQueryData *input_ending_data);
  ~GameLoopRender() override;

  void render_world();
  void render_hud();
  void render_end();

  void render() override;
};
