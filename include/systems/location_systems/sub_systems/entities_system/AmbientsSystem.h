//
// Created by vydra on 8/14/20.
//

#pragma once

#include <vector>

#include "entities/location_entities/ambient_entities/Ambient.h"

class AmbientsSystem {
 protected:
  std::vector<Ambient*> ambients;

 public:
  explicit AmbientsSystem();
  ~AmbientsSystem();

  virtual unsigned get_ambients_size() const;
  int get_ambient_index(Ambient *input_ambient);
  int get_ambient_index(unsigned input_x, unsigned input_y);
  const Ambient *get_ambient(unsigned input_index) const;

 protected:
  virtual void put_ambient(Ambient *input_ambient);
  virtual Ambient *remove_ambient(unsigned input_index);
};
