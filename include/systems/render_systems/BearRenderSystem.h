//
// Created by vydra on 8/11/20.
//

#pragma once

#include <string>

#include "./BearLibTerminal.h"
#include "adds/log_systems/PseudoLogSystem.hpp"
#include "components/sub_components/SubResolution.hpp"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "entities/render_entities/game_loop_render/GameLoopRender.h"
#include "entities/render_entities/main_menu_render/MainMenuRender.h"
#include "entities/render_entities/settings_render/SettingsRender.hpp"
#include "entities/render_entities/statistics_render/StatisticsRender.hpp"
#include "systems/launcher_system/data/ParameterQueryDataSet.hpp"
#include "systems/render_systems/IRenderSystem.h"

/*
 * Class response all terminal options.
 * It means that resolution, window's title, fullscreen mode, graphic's type is under control by this class.
 */
class BearRenderSystem : public IRenderSystem {
 private:
  unsigned SCREENMODE_X = 0;
  unsigned SCREENMODE_Y = 0;

  bool is_pseudo = true;
  IRender* render_entity = nullptr;

  bool is_menu = false;
  ParameterQueryData* menu_data = nullptr;

  bool is_score_list = false;
  StringsListData* score_list_data = nullptr;

  bool is_settings_list = false;
  ParameterQueryData* settings_data = nullptr;

  bool is_game_loop = false;
  IWorldSystem* world_system = nullptr;
  ParameterQueryDataSet* data = nullptr;

 public:
  void reset_render() override;
  void set_resolution_1280x720() override;
  void set_resolution_1920x1080() override;
  void set_pseudo_mode() override;
  void set_grafic_mode() override;

  explicit BearRenderSystem(const SubResolution* input_resolution);
  ~BearRenderSystem() override;

  void set_main_menu_data(ParameterQueryData* input_menu_data) override;
  void set_score_list_data(StringsListData* input_score_list_data) override;
  void set_settings_data(ParameterQueryData* input_settings_data) override;
  void set_game_loop_data(IWorldSystem* input_world_system, ParameterQueryDataSet* input_ending_data) override;

  void set_main_menu_render() override;
  void set_score_list_render() override;
  void set_setting_render() override;
  void set_pseudo_game_loop_render() override;

  void render() override;
};
