//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_RACES_H_
#define INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_RACES_H_

#include <vector>

#include "ecs/entities/location_enities/races_entities/Sentient.h"

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

#endif  // INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_RACES_H_
