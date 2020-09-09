//
// Created by vydra on 9/10/20.
//

#include "entities/scenes_entities/configuration_scene/sub_scenes/GraphicConfigurationScene.hpp"

#include <string>

GraphicConfigurationScene::GraphicConfigurationScene(IRenderSystem *input_render_system,
                                                     GameConfigurationData *input_configuration_data)
    : IScene("GraphicConfigurationScene") {
  std::string temp_choices[2] = {"Изменить текущее разрешение", "Изменить режим отображения объектов"};
  data = new ParameterQueryData(new std::string("Конфигурация графического режима:"),
                                ParameterQueryData::create_choices(2, temp_choices));
  gco_input = new GCOControls(data, input_configuration_data);

  global_settings_data = input_configuration_data;
  render_system = input_render_system;
  render_system->set_settings_data(data);
  render_system->set_setting_render();
}

GraphicConfigurationScene::~GraphicConfigurationScene() {
  render_system = nullptr;
  delete gco_input;
}

unsigned GraphicConfigurationScene::get_highlighted() const {
  return data->get_highlighted();
}

void GraphicConfigurationScene::run() {
  do {
    render_system->render();
    last_control = gco_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "GCOControlSelectExit") != 0);
}
