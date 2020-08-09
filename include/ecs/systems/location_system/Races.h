//
// Created by vydra on 8/3/20.
//

#pragma once

#include <vector>

#include "core/entities/location_enities/sentients_entities/Sentient.h"

class Races {
 private:
  std::vector<Sentient> vec_races;

 public:
  explicit Races(unsigned input_count);
  ~Races();

  void put_player(Sentient *input_player);
  Sentient *remove_player();

  void put_race(Sentient *input_race);
  Sentient *remove_race(unsigned input_index);

  Sentient *get_player();
  Sentient *get_race(unsigned input_index);

  unsigned get_size() const;
  const Sentient *get_player() const;
  const Sentient *get_race(unsigned input_index) const;
};
