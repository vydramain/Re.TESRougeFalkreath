//
// Created by vydra on 9/3/20.
//

#pragma once

#include <cstdio>
#include <string>
#include <vector>

#include "systems/scenes_systems/game_loop_systems/reader/map//MapReader.hpp"

class MapItemReader : public MapReader {
 private:
  char* item_type = nullptr;
  unsigned items_count = 0;
  std::vector<std::pair<unsigned, unsigned>> items_location;

  void clear_item_data();

 public:
  explicit MapItemReader(std::string input_file_name);
  ~MapItemReader() override;

  bool open() override;
  bool has_item();
  bool load_item();
  std::string get_item_type();
  unsigned get_items_count();
  unsigned get_item_x(unsigned input_item_index);
  unsigned get_item_y(unsigned input_item_index);
};
