//
// Created by vydra on 7/31/20.
//

#pragma once

#include "entities/data_entities/GameConfigurationData.hpp"
#include "entities/data_entities/ParameterQueryData.hpp"
#include "entities/scenes_entities/configuration_scene/sub_scenes/GamePlayConfigurationScene.hpp"
#include "entities/scenes_entities/configuration_scene/sub_scenes/GraphicConfigurationScene.hpp"
#include "systems/IControl.h"

class COControlSelectEnter : public IControl {
  GameConfigurationData *global_configuration_data;
  ParameterQueryData *type_configuration;
  IRenderSystem *render_system;

 public:
  explicit COControlSelectEnter(IRenderSystem *input_render_system, ParameterQueryData *input_type_configuration,
                                GameConfigurationData *input_global_configuration_data)
      : IControl("COControlSelectEnter") {
    global_configuration_data = input_global_configuration_data;
    type_configuration = input_type_configuration;
    render_system = input_render_system;
  }
  ~COControlSelectEnter() override = default;

  void execute() override {
    IScene *scene = nullptr;
    if (type_configuration->get_highlighted() == 1) {
      scene = new GamePlayConfigurationScene(render_system, global_configuration_data);
      scene->run();
    }
    if (type_configuration->get_highlighted() == 2) {
      scene = new GraphicConfigurationScene(render_system, global_configuration_data);
      scene->run();
    }
    delete scene;
    render_system->set_settings_data(type_configuration);
    render_system->set_setting_render();
  }
};
