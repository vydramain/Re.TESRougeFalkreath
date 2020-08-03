//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_RACES_H_
#define INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_RACES_H_

#include <vector>

#include "ecs/entities/races_entities/Race.h"

class Races {
 private:
  std::vector<Race> vec_races;

 public:
  explicit Races(unsigned input_count);
  ~Races();

  void put_player(Race *input_player);
  Race *remove_player();

  void put_race(Race *input_race);
  Race *remove_race(unsigned input_index);

  Race *get_player();
  Race *get_race(unsigned input_index);

  unsigned get_size() const;
  const Race *get_player() const;
  const Race *get_race(unsigned input_index) const;
};

#endif  // INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_RACES_H_
