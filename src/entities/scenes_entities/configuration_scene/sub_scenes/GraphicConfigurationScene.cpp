//
// Created by vydra on 9/10/20.
//

#include "entities/scenes_entities/configuration_scene/sub_scenes/GraphicConfigurationScene.hpp"

#include <string>
#include <vector>

GraphicConfigurationScene::GraphicConfigurationScene(IRenderSystem *input_render_system,
                                                     GameConfigurationData *input_configuration_data)
    : IScene("GraphicConfigurationScene") {
  configuration_data = new std::vector<ParameterQueryData *>();
  auto temp_vector = new std::vector<std::string *>();
  temp_vector->push_back(new std::string("Изменить текущее разрешение"));
  temp_vector->push_back(new std::string("Изменить режим отображения объектов"));
  configuration_data->push_back(
      new ParameterQueryData(new std::string("Конфигурация графического режима:"), temp_vector));

  temp_vector = new std::vector<std::string *>();
  temp_vector->push_back(new std::string("1920x1080"));
  temp_vector->push_back(new std::string("1280x720"));
  configuration_data->push_back(new ParameterQueryData(new std::string("Выберете новое разрешение:"), temp_vector));

  temp_vector = new std::vector<std::string *>();
  temp_vector->push_back(new std::string("Использовать псевдографический режим"));
  temp_vector->push_back(new std::string("Использовать графический режим"));
  configuration_data->push_back(
      new ParameterQueryData(new std::string("Выберете режим отоборажения объектов:"), temp_vector));

  global_settings_data = input_configuration_data;
  gco_input = new GCOControls(configuration_data, input_configuration_data);

  render_system = input_render_system;
  render_system->set_settings_data(configuration_data->at(0));
  render_system->set_setting_render();
}

GraphicConfigurationScene::~GraphicConfigurationScene() {
  render_system = nullptr;
  delete gco_input;
}

unsigned GraphicConfigurationScene::get_highlighted() const {
  return configuration_data->at(0)->get_highlighted();
}

void GraphicConfigurationScene::run() {
  do {
    render_system->render();
    last_control = gco_input->update();
    last_control->execute();
    render_system->set_settings_data(configuration_data->at(0));
    render_system->set_setting_render();
  } while (std::strcmp(last_control->get_name(), "GCOControlSelectExit") != 0 ||
           std::strcmp(configuration_data->at(0)->get_title()->data(), "Конфигурация графического режима:") != 0);
}
