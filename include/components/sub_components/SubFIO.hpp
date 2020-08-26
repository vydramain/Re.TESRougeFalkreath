//
// Created by vydra on 8/18/20.
//

#pragma once

#include <cstring>

#include "components/abs_components/AbsFIO.hpp"

class SubFIO : protected AbsFIO {
 public:
  explicit SubFIO(const char* input_fio);
  ~SubFIO();

  unsigned get_chars_counts() const;
  const char* get_fio() const;
  void set_fio(const char* input_fio);
};