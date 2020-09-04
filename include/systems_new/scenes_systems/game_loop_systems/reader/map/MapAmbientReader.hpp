//
// Created by vydra on 9/3/20.
//

#pragma once

#include <cstdio>
#include <string>

#include "systems_new/scenes_systems/game_loop_systems/reader/map//MapReader.hpp"

class MapAmbientReader : public MapReader {
 public:
  explicit MapAmbientReader(std::string input_file_name);
  ~MapAmbientReader() override;

  bool open() override;
  bool has_next();
  unsigned int get_char();
};
