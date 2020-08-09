//
// Created by vydra on 16.07.2020.
//

#pragma once

#include <vector>

#include "core/entities/location_enities/magwehrs_entities/Magwehr.h"

class MagwehrsSystem {
 private:
  std::vector<Magwehr*> magwehrs;

 public:
  explicit MagwehrsSystem(unsigned input_count);
  ~MagwehrsSystem();

  void put_magwehr(Magwehr *input_creature);
  Magwehr *remove_magwehr(unsigned input_index);

  unsigned get_size() const;

  Magwehr *get_magwehr(unsigned input_index);
  const Magwehr *get_magwehr(unsigned input_index) const;
};
