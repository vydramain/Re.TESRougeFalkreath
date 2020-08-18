//
// Created by vydra on 8/18/20.
//

#pragma once

class AbsFIO {
 protected:
  const unsigned char_counts = 24;
  const char* fio = nullptr;

  explicit AbsFIO() = default;
  ~AbsFIO() = default;
};