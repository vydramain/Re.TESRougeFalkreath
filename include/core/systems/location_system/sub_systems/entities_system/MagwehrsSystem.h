//
// Created by vydra on 16.07.2020.
//

#pragma once

#include <vector>

#include "core/entities/location_enities/magwehrs_entities/Magwehr.h"

class MagwehrsSystem {
 protected:
  std::vector<Magwehr*> magwehrs;

 public:
  explicit MagwehrsSystem();
  virtual ~MagwehrsSystem();

  unsigned get_magwehrs_size() const;
  int get_magwehr_index(Magwehr *input_magwehr);
  const Magwehr *get_magwehr(unsigned input_index) const;

 protected:
  virtual void put_magwehr(Magwehr *input_creature);
  virtual Magwehr *remove_magwehr(unsigned input_index);
};
