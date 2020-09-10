//
// Created by vydra on 9/10/20.
//

#pragma once

#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IScene.h"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/game_play_configuration_controls/GPCOControls.h"

class GamePlayConfigurationScene : public IScene {
 private:
  GameConfigurationData *global_settings_data = nullptr;
  ParameterQueryData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  GPCOControls *gpco_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit GamePlayConfigurationScene(IRenderSystem *input_render_system,
                                      GameConfigurationData *input_configuration_data);
  ~GamePlayConfigurationScene() override;

  unsigned get_highlighted() const;

  void run() override;
};
