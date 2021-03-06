//
// Created by vydra on 9/3/20.
//

#pragma once

#include <cstdio>
#include <string>
#include <utility>

#include "systems/scenes_systems/game_loop_systems/reader/map//MapReader.hpp"

class MapTitleReader : public MapReader {
 private:
  std::string map_name;
  unsigned size_x = 0;
  unsigned size_y = 0;

 public:
  explicit MapTitleReader(std::string* input_file_name);
  ~MapTitleReader() override;

  bool open() override;
  std::string get_map_name();
  unsigned int get_map_size_x() const;
  unsigned int get_map_size_y() const;
};
