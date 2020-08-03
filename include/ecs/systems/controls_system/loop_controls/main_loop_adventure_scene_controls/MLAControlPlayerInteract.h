//
// Created by vydra on 8/3/20.
//

#ifndef INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERINTERACT_H_
#define INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERINTERACT_H_

#include "ecs/systems/controls_system/IControl.h"
#include "ecs/systems/location_system/Location.h"

class MLAControlPlayerInteract : public IControl {
 private:
  Location* location;

 public:
  explicit MLAControlPlayerInteract(Location* input_location)
      : IControl("MLAControlPlayerInteract"), location(input_location) {}

  void execute() override {
    int index = location->get_items()->get_item_index(location->get_races()->get_player()->get_sight_x(),
                                                         location->get_races()->get_player()->get_sight_y());
    if (index != -1) {
      location->get_races()->get_player()->put_item(*location->get_items()->remove_item(index));
    }
  }
};

#endif  // INCLUDE_ECS_SYSTEMS_CONTROLS_SYSTEM_LOOP_CONTROLS_MAIN_LOOP_ADVENTURE_SCENE_CONTROLS_MLACONTROLPLAYERINTERACT_H_
