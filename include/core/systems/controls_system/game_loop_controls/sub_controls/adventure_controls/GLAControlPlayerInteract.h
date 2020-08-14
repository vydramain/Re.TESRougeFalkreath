//
// Created by vydra on 8/3/20.
//

#pragma once

#include <cstring>

#include "core/systems/controls_system/IControl.h"
#include "core/systems/location_system/LocationSystem.h"

class GLAControlPlayerInteract : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerInteract(LocationSystem* input_location)
      : IControl("GLAControlPlayerInteract"), location(input_location) {}

  void execute() override {
    int index = location->get_entities()->get_item_index(location->get_entities()->get_player()->get_sight_x(),
                                                         location->get_entities()->get_player()->get_sight_y());
    if (index != -1) {
      if (std::strcmp(location->get_entities()->remove_item(index)->get_name(), "Coin") == 0) {
        printf("%s%s%s", "[GLAControlPlayerInteract] - ", location->get_entities()->get_player()->get_name(),
               " interact with Coin\n");
        location->get_entities()->get_player()->set_wallet(location->get_entities()->get_player()->get_wallet() + 1);
      } else {
        printf("%s%s%s%s%s", "[GLAControlPlayerInteract] - ", location->get_entities()->get_player()->get_name(),
               " interact with ", location->get_entities()->get_item(index)->get_name(), "\n");
        location->get_entities()->get_player()->put_item(location->get_entities()->remove_item(index));
      }
    }
  }
};
