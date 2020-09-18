//
// Created by vydra on 8/18/20.
//

#include "components/sub_components/SubNickname.hpp"

#include <string>

SubNickname::SubNickname(const char *input_fio) {
  if (strlen(input_fio) > 24) {
    return;
  }
  nickname = new std::string(input_fio);
}

SubNickname::~SubNickname() = default;

unsigned SubNickname::get_chars_counts() const {
  return nickname->size();
}

std::string *SubNickname::get_nickname() const {
  return nickname;
}

void SubNickname::set_nickname(std::string *input_fio) {
  nickname = input_fio;
}
