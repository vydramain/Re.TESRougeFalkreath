//
// Created by vydra on 9/10/20.
//

#include "entities/scenes_entities/configuration_scene/sub_scenes/GamePlayConfigurationScene.hpp"

#include <string>

GamePlayConfigurationScene::GamePlayConfigurationScene(IRenderSystem *input_render_system,
                                                       GameConfigurationData *input_configuration_data)
    : IScene("GamePlayConfigurationScene") {
  std::string temp_choices[2] = {"Включить рандомную генерацию подемелий", "Выключить рандомную генерацию подемелий"};
  data = new ParameterQueryData(new std::string("Конфигурация особенностей игрового процесса:"),
                                ParameterQueryData::create_choices(2, temp_choices));
  gpco_input = new GPCOControls(data, input_configuration_data);

  global_settings_data = input_configuration_data;
  render_system = input_render_system;
  render_system->set_settings_data(data);
  render_system->set_setting_render();
}

GamePlayConfigurationScene::~GamePlayConfigurationScene() {
  render_system = nullptr;
  delete gpco_input;
}

unsigned GamePlayConfigurationScene::get_highlighted() const {
  return data->get_highlighted();
}

void GamePlayConfigurationScene::run() {
  do {
    render_system->render();
    last_control = gpco_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "GPCOControlSelectExit") != 0);
}
