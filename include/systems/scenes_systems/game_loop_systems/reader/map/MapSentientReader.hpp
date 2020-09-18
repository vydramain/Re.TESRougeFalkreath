//
// Created by vydra on 9/17/20.
//

#pragma once

#include <string>
#include <vector>

#include "systems/scenes_systems/game_loop_systems/reader/map/MapReader.hpp"

class MapSentientReader : public MapReader {
 private:
  std::string sentient_name;
  std::string sentient_nickname;
  unsigned sentient_x, sentient_y;

  void clear_sentient_data();

 public:
  explicit MapSentientReader(std::string* input_file_name);
  ~MapSentientReader() override;

  bool open() override;
  bool has_sentient();
  bool load_sentient();
  std::string get_sentient_name();
  std::string get_sentient_nickname();
  unsigned get_sentient_x() const;
  unsigned get_sentient_y() const;
};