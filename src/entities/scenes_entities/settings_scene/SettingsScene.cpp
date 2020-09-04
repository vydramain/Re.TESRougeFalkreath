//
// Created by vydra on 9/5/20.
//

#include "entities/scenes_entities/settings_scene/SettingsScene.hpp"

SettingsScene::SettingsScene(IRenderSystem *input_render_system) {
  std::string temp_choices[2] = {"Включить рандомную генерацию подемелий", "Выключить рандомную генерацию подемелий"};
  data =
      new ParameterQueryData(new std::string("Настройки:"), 2, ParameterQueryData::create_choices(2, temp_choices));

  s_input = new SEControls(data);

  PseudoLogSystem::log("SettingsScene", "Set up render system");
  render_system = input_render_system;
  render_system->set_settings_data(data);
  render_system->set_setting_render();
}

SettingsScene::~SettingsScene() {
  render_system = nullptr;
  delete s_input;
}

unsigned SettingsScene::get_highlighted() const {
  return data->get_highlighted();
}

void SettingsScene::run() {
  PseudoLogSystem::log("SettingsScene", "Launch settings");
  do {
    render_system->render();
    last_control = s_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "SEControlSelectExit") != 0 &&
           std::strcmp(last_control->get_name(), "SEControlSelectEnter") != 0);

  if (std::strcmp(last_control->get_name(), "SEControlSelectExit") == 0) {
    data->set_highlighted(1);
  }
}
