//
// Created by vydra on 8/20/20.
//

#pragma once

#include <string>
#include <cstring>

class StringsListData {
 private:
  std::string *title;
  unsigned records_count;
  std::string **records;
  unsigned pages_count;
  unsigned current_page;

 public:
  explicit StringsListData();
  ~StringsListData();

  void set_title(std::string * input_title);
  void set_records_count(unsigned input_count);
  void set_record(unsigned input_index, std::string* input_record);
  void set_pages_count(unsigned input_count);
  void set_current_page(unsigned input_count);

  std::string* get_title() const;
  unsigned get_records_count() const;
  std::string* get_record(unsigned input_index);
  unsigned get_pages_count() const;
  unsigned get_current_page() const;
};
