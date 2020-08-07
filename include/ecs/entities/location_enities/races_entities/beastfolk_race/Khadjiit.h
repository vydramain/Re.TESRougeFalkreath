//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_ENTITIES_RACES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_
#define INCLUDE_ECS_ENTITIES_RACES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_

#include "ecs/entities/location_enities/races_entities/Sentient.h"

class Khadjiit : public Sentient {
 public:
  explicit Khadjiit(const char *input_name, unsigned input_current_x = 0, unsigned input_current_y = 0,
                    unsigned input_pocket = 10);
};

#endif  // INCLUDE_ECS_ENTITIES_RACES_ENTITIES_BEASTFOLK_RACE_KHADJIIT_H_
