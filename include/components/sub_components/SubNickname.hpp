//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstring>

#include "components/abs_components/AbsNickname.hpp"

class SubNickname : protected AbsNickname {
 public:
  explicit SubNickname(const char* input_fio);
  ~SubNickname();

  unsigned get_chars_counts() const;
  const char* get_fio() const;
  void set_fio(const char* input_fio);
};