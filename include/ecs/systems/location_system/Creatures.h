//
// Created by vydra on 16.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_CREATURES_H_
#define INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_CREATURES_H_

#include <vector>

#include "ecs/entities/location_enities/creatures_entities/Creature.h"

class Creatures {
 private:
  std::vector<Creature> vec_creatures;

 public:
  explicit Creatures(unsigned input_count);
  ~Creatures();

  void put_creature(Creature *input_creature);
  Creature *remove_creature(unsigned input_index);

  unsigned get_size() const;

  Creature *get_creature(unsigned input_index);
  const Creature *get_creature(unsigned input_index) const;
};

#endif  // INCLUDE_ECS_SYSTEMS_LOCATION_SYSTEM_CREATURES_H_
