//
// Created by vydra on 9/17/20.
//

#include "systems/scenes_systems/game_loop_systems/load/controls/data/LoadControlsEntitysData.hpp"

#include <string>

LoadControlsEntitysData::LoadControlsEntitysData() {
  name = nullptr;
  nickname = nullptr;
  x = 0;
  y = 0;
}

LoadControlsEntitysData::LoadControlsEntitysData(std::string* input_name, std::string* input_nickname,
                                                 unsigned int input_x, unsigned int input_y) {
  name = input_name;
  nickname = input_nickname;
  x = input_x;
  y = input_y;
}

LoadControlsEntitysData::~LoadControlsEntitysData() {
  clear_fields();
}

void LoadControlsEntitysData::set_name(std::string* input_name) {
  delete name;
  name = input_name;
}

void LoadControlsEntitysData::set_nickname(std::string* input_nickname) {
  delete nickname;
  nickname = input_nickname;
}

void LoadControlsEntitysData::set_x(unsigned int input_x) {
  x = input_x;
}

void LoadControlsEntitysData::set_y(unsigned int input_y) {
  y = input_y;
}

std::string* LoadControlsEntitysData::get_name() const {
  return name;
}

std::string* LoadControlsEntitysData::get_nickname() const {
  return nickname;
}

unsigned int LoadControlsEntitysData::get_x() const {
  return x;
}

unsigned int LoadControlsEntitysData::get_y() const {
  return y;
}

void LoadControlsEntitysData::clear_fields() {
  delete name;
  delete nickname;

  name = nullptr;
  nickname = nullptr;

  x = 0;
  y = 0;
}
