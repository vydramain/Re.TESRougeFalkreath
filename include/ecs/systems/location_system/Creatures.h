//
// Created by vydra on 16.07.2020.
//

#pragma once

#include <vector>

#include "core/entities/location_enities/magwehrs_entities/Magwehr.h"

class Creatures {
 private:
  std::vector<Magwehr> vec_creatures;

 public:
  explicit Creatures(unsigned input_count);
  ~Creatures();

  void put_creature(Magwehr *input_creature);
  Magwehr *remove_creature(unsigned input_index);

  unsigned get_size() const;

  Magwehr *get_creature(unsigned input_index);
  const Magwehr *get_creature(unsigned input_index) const;
};
