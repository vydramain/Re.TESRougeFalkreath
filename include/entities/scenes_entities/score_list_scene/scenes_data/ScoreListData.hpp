//
// Created by vydra on 8/20/20.
//

#pragma once

#include <string>
#include <cstring>

class ScoreListData {
 private:
  const char *title = "Результаты:";
  unsigned records_count = 0;
  std::string **records = nullptr;
  unsigned pages_count = 0;
  unsigned current_page = 0;

 public:
  explicit ScoreListData();
  ~ScoreListData();

  void set_title(const char *input_title);
  void set_records_count(unsigned input_count);
  void set_record(unsigned input_index, const char* input_record);
  void set_pages_count(unsigned input_count);
  void set_current_page(unsigned input_count);

  const char* get_title();
  unsigned get_records_count();
  const char* get_record(unsigned input_index);
  unsigned get_pages_count();
  unsigned get_current_page();
};
