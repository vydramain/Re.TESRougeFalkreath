//
// Created by vydra on 8/19/20.
//

#include "entities/render_entities/statistics_render/StatisticsRender.hpp"

#include <string>
#include <vector>

void StatisticsRender::render_title() {
  auto *render_title = new std::vector<std::string *>;
  render_title->push_back(score_list_data->get_title());
  TextPanelsRender::view_strings_list(0, 0, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_title);
}

std::vector<std::string *> *StatisticsRender::create_records() {
  auto *records = new std::vector<std::string *>();
  for (unsigned i = 0; i < records_count && i < score_list_data->get_records_count(); i++) {
    records->push_back(score_list_data->get_record(i + score_list_data->get_current_page() * records_count));
  }

  return records;
}

void StatisticsRender::render_filled_list() {
  unsigned i = score_list_data->get_records_count();
  if (i > records_count) {
    i = records_count;
  }
  auto render_records = create_records();
  TextPanelsRender::view_strings_list(0, 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_records);

  auto render_message = new std::vector<std::string *>();
  render_message->push_back(new std::string("Нажмите 'Delete', чтобы отчистить"));
  TextPanelsRender::view_strings_list(SCREENMODE_X - 37, SCREENMODE_Y - 5, SCREENMODE_X - 1, SCREENMODE_Y - 1,
                                      render_message);
  if (score_list_data->get_pages_count() > 0) {
    auto render_navigation = new std::vector<std::string *>();
    render_navigation->push_back(new std::string("Используйте ← →, чтобы перемещаться по таблице"));
    TextPanelsRender::view_strings_list(0, SCREENMODE_Y - 5, 50, SCREENMODE_Y - 1, render_navigation);
  }
}

void StatisticsRender::render_empty_list() {
  auto render_records = new std::vector<std::string *>();
  render_records->push_back(new std::string("Результаты отсутствуют"));
  TextPanelsRender::view_strings_list(0, 5, SCREENMODE_X - 1, SCREENMODE_Y - 1, render_records);
}

StatisticsRender::StatisticsRender(unsigned int input_screen_x, unsigned int input_screen_y,
                                   StringsListData *input_score_list_data) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  score_list_data = input_score_list_data;
}

StatisticsRender::~StatisticsRender() {
  score_list_data = nullptr;
}

void StatisticsRender::render() {
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
