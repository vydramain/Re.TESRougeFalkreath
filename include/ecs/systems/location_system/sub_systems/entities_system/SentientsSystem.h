//
// Created by vydra on 8/3/20.
//

#pragma once

#include <vector>

#include "core/entities/location_enities/sentients_entities/Sentient.h"

class SentientsSystem {
 private:
  std::vector<Sentient*> sentients;

 public:
  explicit SentientsSystem(unsigned input_count);
  ~SentientsSystem();

  void put_player(Sentient *input_player);
  Sentient *remove_player();

  void put_sentient(Sentient *input_sentient);
  Sentient *remove_sentient(unsigned input_index);

  Sentient *get_player();
  Sentient *get_sentient(unsigned input_index);

  unsigned get_size() const;
  const Sentient *get_player() const;
  const Sentient *get_sentient(unsigned input_index) const;
};
