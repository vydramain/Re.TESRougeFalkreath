//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_ENTITIES_CREATURES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_
#define INCLUDE_ECS_ENTITIES_CREATURES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_

#include "ecs/components/Pocket.h"
#include "ecs/entities/creatures_entities/Creature.h"

class Khadjiit : public Creature, public Pocket {
 public:
  explicit Khadjiit(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0,
                    unsigned input_pocket = 10);
};

#endif  // INCLUDE_ECS_ENTITIES_CREATURES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_
