//
// Created by vydra on 9/3/20.
//

#pragma once

#include <cstdio>
#include <string>
#include <vector>

class ItemReader {
 private:
  const char* file_name = nullptr;
  FILE* file = nullptr;

  char* item_type = nullptr;
  unsigned items_count = 0;
  std::vector<std::pair<unsigned, unsigned>> items_location;

  void clear_item_data();

 public:
  explicit ItemReader(const char* input_file_name);
  ~ItemReader();

  const char* get_file_name();

  bool open();
  bool has_item();
  bool load_item();
  std::string get_item_type();
  unsigned get_items_count();
  unsigned get_item_x(unsigned input_item_index);
  unsigned get_item_y(unsigned input_item_index);
};
