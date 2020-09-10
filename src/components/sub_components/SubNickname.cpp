//
// Created by vydra on 8/18/20.
//

#include "components/sub_components/SubNickname.hpp"

SubNickname::SubNickname(const char *input_fio) {
  if (strlen(input_fio) > 24) {
    return;
  }
  fio = input_fio;
}

SubNickname::~SubNickname() = default;

unsigned SubNickname::get_chars_counts() const {
  return char_counts;
}

const char *SubNickname::get_fio() const {
  return fio;
}
void SubNickname::set_fio(const char *input_fio) {
  if (strlen(input_fio) > 24) {
    return;
  }
  fio = input_fio;
}
