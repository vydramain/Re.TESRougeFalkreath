//
// Created by vydra on 8/19/20.
//

#include "entities/render_entities/score_list_render/ScoreListRender.hpp"

void ScoreListRender::render_title() {
  std::string *render_title[1] = {score_list_data->get_title()};
  TextPanelsRender::view_strings_list(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_title, 1);
}

std::string **ScoreListRender::create_records() {
  std::string **records;
  if (score_list_data->get_records_count() < 15) {
    records = new std::string *[score_list_data->get_records_count()];
  } else {
    records = new std::string *[15];
  }

  unsigned i;
  for (i = 0; i < 15 && i < score_list_data->get_records_count(); i++) {
    records[i] = score_list_data->get_record(i + score_list_data->get_current_page() * 15);
  }

  return records;
}

void ScoreListRender::render_filled_list() {
  unsigned i = score_list_data->get_records_count();
  if (i > 15) {
    i = 15;
  }
  std::string **render_records = create_records();
  TextPanelsRender::view_strings_list(0, 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_records, i);

  std::string *render_message[1] = {new std::string("Нажмите 'Delete', чтобы отчистить")};
  TextPanelsRender::view_strings_list(SCREENMODE_X - 37, SCREENMODE_Y - 5, SCREENMODE_X - 1, SCREENMODE_Y - 1,
                                      render_message, 1);
  if (score_list_data->get_pages_count() > 0) {
    std::string *render_navigation[1] = {new std::string("Используйте ← →, чтобы перемещаться по таблице")};
    TextPanelsRender::view_strings_list(0, SCREENMODE_Y - 5, 50, SCREENMODE_Y - 1, render_navigation, 1);
  }
}

void ScoreListRender::render_empty_list() {
  std::string *render_records[1] = {new std::string("Результаты отсутствуют")};
  TextPanelsRender::view_strings_list(0, 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_records, 1);
}

ScoreListRender::ScoreListRender(unsigned int input_screen_x, unsigned int input_screen_y,
                                 StringsListData *input_score_list_data) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  score_list_data = input_score_list_data;
}

ScoreListRender::~ScoreListRender() {
  score_list_data = nullptr;
}

void ScoreListRender::render() {
  CleanerRender::clean_all();
  terminal_color(0xFFcccccc);
  render_title();

  if (score_list_data->get_records_count() > 0) {
    render_filled_list();
  } else {
    render_empty_list();
  }

  terminal_refresh();
}
