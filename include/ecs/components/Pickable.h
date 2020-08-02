//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_COMPONENTS_PICKABLE_H_
#define INCLUDE_ECS_COMPONENTS_PICKABLE_H_

#include "ecs/components/Locateable.h"

class Pickable : public Locateable {
 private:
  bool picked_up;

 public:
  explicit Pickable(bool input_pick = false, unsigned input_x = 0, unsigned input_y = 0);
  ~Pickable();

  void ejected(unsigned input_x, unsigned input_y);
  void pick_up();
  bool has_pick_up() const;
};

#endif  // INCLUDE_ECS_COMPONENTS_PICKABLE_H_
