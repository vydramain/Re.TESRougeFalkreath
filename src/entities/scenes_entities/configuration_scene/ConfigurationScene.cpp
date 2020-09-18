//
// Created by vydra on 9/5/20.
//

#include "entities/scenes_entities/configuration_scene/ConfigurationScene.hpp"

#include <string>

ConfigurationScene::ConfigurationScene(IRenderSystem* input_render_system,
                                       GameConfigurationData* input_configuration_data) {
  std::string temp_choices[2] = {"Конфигурация особенностей игрового процесса", "Конфигурация графического режима"};
  data = new ParameterQueryData(new std::string("configuration_data"), new std::string("Конфигурация:"),
                                ParameterQueryData::create_choices(2, temp_choices));
  co_input = new COControls(input_render_system, data, input_configuration_data);

  global_configuration_data = input_configuration_data;
  PseudoLogSystem::log("ConfigurationScene", "Set up render system");
  render_system = input_render_system;
  render_system->set_settings_data(data);
  render_system->set_setting_render();
}

ConfigurationScene::~ConfigurationScene() {
  render_system = nullptr;
  delete co_input;
}

unsigned ConfigurationScene::get_highlighted() const {
  return data->get_highlighted();
}

void ConfigurationScene::run() {
  PseudoLogSystem::log("ConfigurationScene", "Launch configuration");
  do {
    render_system->render();
    last_control = co_input->update();
    last_control->execute();
    render_system->set_settings_data(data);
    render_system->set_setting_render();
  } while (std::strcmp(last_control->get_name(), "COControlSelectExit") != 0);
}
