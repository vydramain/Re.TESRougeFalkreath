//
// Created by vydra on 9/10/20.
//

#pragma once

#include "entities/GameConfigurationData.hpp"
#include "entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/IScene.h"
#include "systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/configuration_systems/controls/sub_controls/graphic_configuration_controls/GCOControls.h"

class GraphicConfigurationScene : public IScene {
 private:
  GameConfigurationData *global_settings_data = nullptr;
  ParameterQueryData *data = nullptr;
  IRenderSystem *render_system = nullptr;

  GCOControls *gco_input = nullptr;
  IControl *last_control = nullptr;

 public:
  explicit GraphicConfigurationScene(IRenderSystem *input_render_system,
                                     GameConfigurationData *input_configuration_data);
  ~GraphicConfigurationScene() override;

  unsigned get_highlighted() const;

  void run() override;
};
