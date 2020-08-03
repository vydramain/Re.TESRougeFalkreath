//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_ENTITIES_RACES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_
#define INCLUDE_ECS_ENTITIES_RACES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_

#include "ecs/components/Pocket.h"
#include "ecs/entities/races_entities/Race.h"

class Khadjiit : public Race {
 public:
  explicit Khadjiit(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0,
                    unsigned input_pocket = 10);
};

#endif  // INCLUDE_ECS_ENTITIES_RACES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_
