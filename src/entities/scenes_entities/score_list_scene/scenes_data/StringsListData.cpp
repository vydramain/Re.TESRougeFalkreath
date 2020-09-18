//
// Created by vydra on 8/20/20.
//

#include "entities/render_entities/data/StringsListData.hpp"

#include <string>

StringsListData::StringsListData() {
  title = new std::string("Статистика:");
  records_count = 0;
  records = nullptr;
  pages_count = 0;
  current_page = 0;
}

StringsListData::~StringsListData() {
  if (records != nullptr) {
    for (unsigned i = 0; i < records_count; i++) {
      delete records[i];
    }
    delete[] records;
  }
}
void StringsListData::set_title(std::string *input_title) {
  delete title;
  title = input_title;
}

void StringsListData::set_records_count(unsigned int input_count) {
  if (records != nullptr) {
    for (unsigned i = 0; i < records_count; i++) {
      delete records[i];
    }
    delete[] records;
  }
  records_count = input_count;
  records = new std::string *[input_count];
}

void StringsListData::set_record(unsigned int input_index, std::string *input_record) {
  if (input_index < records_count) {
    records[input_index] = input_record;
  }
}

void StringsListData::set_pages_count(unsigned int input_count) {
  pages_count = input_count;
}

void StringsListData::set_current_page(unsigned int input_count) {
  current_page = input_count;
}

std::string *StringsListData::get_title() const {
  return title;
}

unsigned StringsListData::get_records_count() const {
  return records_count;
}

std::string *StringsListData::get_record(unsigned int input_index) {
  if (records_count > input_index) {
    return records[input_index];
  }
  return nullptr;
}

unsigned StringsListData::get_pages_count() const {
  return pages_count;
}

unsigned StringsListData::get_current_page() const {
  return current_page;
}
