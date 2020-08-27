//
// Created by vydra on 8/19/20.
//

#include "entities/scenes_entities/score_list_scene/ScoreListScene.hpp"

ScoreListScene::ScoreListScene(IRenderSystem *input_render_system) {
  data = new ScoreListData();
  score_system = new StdScoreSystem();
  update_fields();
  sl_input = new SLControls(score_system, data);

  render_system = input_render_system;
  render_system->set_score_list_data(data);
  render_system->set_score_list_render();
}

ScoreListScene::~ScoreListScene() {
  delete data;
  delete sl_input;
  delete score_system;
}

void ScoreListScene::update_fields() {
  if (score_system != nullptr && data != nullptr) {
    data->set_records_count(score_system->get_records_count());
    for (unsigned i = 0; i < data->get_records_count(); i++) {
      data->set_record(i, score_system->get_score_string(i));
    }
    data->set_pages_count(data->get_records_count() / 15);
    data->set_current_page(0);
    return;
  }
}

void ScoreListScene::run() {
  printf("%s", "[ScoreListScene] - Launch score list\n");
  do {
    render_system->render();
    last_control = sl_input->update();
    last_control->execute();
  } while (std::strcmp(last_control->get_name(), "SLControlSelectExit") != 0);
}
