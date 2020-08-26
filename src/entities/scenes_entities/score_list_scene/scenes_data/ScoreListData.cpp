//
// Created by vydra on 8/20/20.
//

#include <string>

#include "entities/scenes_entities/score_list_scene/scenes_data/ScoreListData.hpp"

ScoreListData::ScoreListData() = default;

ScoreListData::~ScoreListData() {
  if (records != nullptr) {
    for (unsigned i = 0; i < records_count; i++) {
      delete records[i];
    }
    delete[] records;
  }
}
void ScoreListData::set_title(const char *input_title) {
  title = input_title;
}

void ScoreListData::set_records_count(unsigned int input_count) {
  if (records != nullptr) {
    for (unsigned i = 0; i < records_count; i++) {
      delete records[i];
    }
    delete[] records;
  }
  records_count = input_count;
  records = new std::string *[input_count];
}

void ScoreListData::set_record(unsigned int input_index, const char *input_record) {
  records[input_index] = new std::string(input_record);
}

void ScoreListData::set_pages_count(unsigned int input_count) {
  pages_count = input_count;
}

void ScoreListData::set_current_page(unsigned int input_count) {
  current_page = input_count;
}

const char *ScoreListData::get_title() {
  return title;
}

unsigned ScoreListData::get_records_count() {
  return records_count;
}

const char *ScoreListData::get_record(unsigned int input_index) {
  if (records_count > input_index) {
    return records[input_index]->c_str();
  }
  return nullptr;
}

unsigned ScoreListData::get_pages_count() {
  return pages_count;
}

unsigned ScoreListData::get_current_page() {
  return current_page;
}
