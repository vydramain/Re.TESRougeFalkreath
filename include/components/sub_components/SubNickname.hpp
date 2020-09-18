//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstring>
#include <string>

#include "components/abs_components/AbsNickname.hpp"

class SubNickname : protected AbsNickname {
 public:
  explicit SubNickname(const char* input_fio);
  ~SubNickname();

  unsigned get_chars_counts() const;
  std::string* get_nickname() const;
  void set_nickname(std::string* input_fio);
};