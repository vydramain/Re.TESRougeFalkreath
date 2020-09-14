//
// Created by vydra on 8/19/20.
//

#include "entities/scenes_entities/statistics_scene/StatisticsScene.hpp"

#include <string>

StatisticsScene::StatisticsScene(IRenderSystem *input_render_system) {
  data = new StringsListData();
  score_system = new StdStatisticsSystem();
  update_fields();
  sl_input = new SControls(score_system, data);

  render_system = input_render_system;
  render_system->set_score_list_data(data);
  render_system->set_score_list_render();
}

StatisticsScene::~StatisticsScene() {
  delete data;
  delete sl_input;
  delete score_system;
}

void StatisticsScene::update_fields() {
  if (score_system != nullptr && data != nullptr) {
    data->set_records_count(score_system->get_records_count());
    for (unsigned i = 0; i < data->get_records_count(); i++) {
      data->set_record(i, new std::string(score_system->get_score_string(i)));
    }
    data->set_pages_count(data->get_records_count() / 15);
    data->set_current_page(0);
    return;
  }
}

void StatisticsScene::run() {
  PseudoLogSystem::log(get_name()->data(), "Launch score list");
  do {
    render_system->render();
    last_control = sl_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "SControlSelectExit") != 0);
}
