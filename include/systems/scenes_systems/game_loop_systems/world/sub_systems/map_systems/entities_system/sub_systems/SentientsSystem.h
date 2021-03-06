//
// Created by vydra on 8/3/20.
//

#pragma once

#include <vector>

#include "entities/location_entities/sentients_entities/Sentient.h"

class SentientsSystem {
 protected:
  std::vector<Sentient *> sentients;

 public:
  explicit SentientsSystem();
  ~SentientsSystem();

  virtual void put_player(Sentient *input_player);
  virtual Sentient *remove_player();

  Sentient *get_player();
  Sentient *get_sentient(unsigned input_index);

  unsigned get_sentients_size() const;
  int get_sentient_index(unsigned input_x, unsigned input_y);
  const Sentient *get_sentient(unsigned input_index) const;

 protected:
  virtual void put_sentient(Sentient *input_sentient);
  virtual Sentient *remove_sentient(unsigned input_index);
};
