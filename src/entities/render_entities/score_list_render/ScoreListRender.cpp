//
// Created by vydra on 8/19/20.
//

#include "entities/render_entities/score_list_render/ScoreListRender.hpp"

ScoreListRender::ScoreListRender(unsigned int input_screen_x, unsigned int input_screen_y,
                                 ScoreListData *input_score_list_data) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  score_list_data = input_score_list_data;
}

ScoreListRender::~ScoreListRender() {
  score_list_data = nullptr;
}

void ScoreListRender::render() {
  CleanerRender::clean_all();
  terminal_color("White");
  const char *render_title[1] = {score_list_data->get_title()};
  TextPanelsRender::view_text(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_title, 1);
  if (score_list_data->get_records_count() > 0) {
  const char **render_records;
  if (score_list_data->get_records_count() < 15) {
    render_records = new const char *[score_list_data->get_records_count()];
  } else {
    render_records = new const char *[15];
  }
  unsigned i;
  for (i = 0; i < 15 && i < score_list_data->get_records_count(); i++) {
    render_records[i] = score_list_data->get_record(i + score_list_data->get_current_page() * 15);
  }
  TextPanelsRender::view_text(0, 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_records, i);

    const char *render_message[1] = {"Нажмите 'Delete', чтобы отчистить"};
    TextPanelsRender::view_text(SCREENMODE_X - 37, SCREENMODE_Y - 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_message,
                                1);
    if (score_list_data->get_pages_count() > 0) {
      const char *render_navigation[1] = {"Используйте ← →, чтобы перемещаться по таблице"};
      TextPanelsRender::view_text(0, SCREENMODE_Y - 5, 50, SCREENMODE_Y - 1, render_navigation, 1);
    }
  } else {
    const char *render_records[1] = {"Результаты отсутствуют"};
    TextPanelsRender::view_text(0, 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_records, 1);
  }
  terminal_refresh();
}
