//
// Created by vydra on 8/3/20.
//

#pragma once

#include <cstring>

#include "systems/controls_systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLAControlPlayerInteract : public IControl {
 private:
  LocationSystem* location;

 public:
  explicit GLAControlPlayerInteract(LocationSystem* input_location)
      : IControl("GLAControlPlayerInteract"), location(input_location) {}

  void execute() override {
    unsigned new_x = location->get_entities()->get_player()->get_sight_x();
    unsigned new_y = location->get_entities()->get_player()->get_sight_y();

    int ambient_index = location->get_entities()->get_ambient_index(new_x, new_y);
    int item_index = location->get_entities()->get_item_index(new_x, new_y);

    if (ambient_index != -1) {
      if (std::strcmp(location->get_entities()->get_ambient(ambient_index)->get_name(), "Door") == 0) {
        printf("%s%s%s%s%s", "[GLAControlPlayerInteract] - ", location->get_entities()->get_player()->get_name(),
               " interact with ", location->get_entities()->get_ambient(ambient_index)->get_name(), "\n");
        if (location->get_entities()->get_ambient(ambient_index)->get_floor()) {
          location->get_entities()->get_ambient(ambient_index)->set_floor(false);
          location->get_entities()->get_ambient(ambient_index)->set_tile("┼");
        } else {
          location->get_entities()->get_ambient(ambient_index)->set_floor(true);
          location->get_entities()->get_ambient(ambient_index)->set_tile("║");
        }
      }

      if (std::strcmp(location->get_entities()->get_ambient(ambient_index)->get_name(), "SouthGate") == 0) {
        printf("%s%s%s%s%s", "[GLAControlPlayerInteract] - ", location->get_entities()->get_player()->get_name(),
               " interact with ", location->get_entities()->get_ambient(ambient_index)->get_name(), "\n");
        location->story_is_over();
      }
    }

    if (item_index != -1) {
      if (std::strcmp(location->get_entities()->remove_item(item_index)->get_name(), "Coin") == 0) {
        printf("%s%s%s", "[GLAControlPlayerInteract] - ", location->get_entities()->get_player()->get_name(),
               " interact with Coin\n");
        location->get_entities()->get_player()->set_wallet(location->get_entities()->get_player()->get_wallet() + 1);
      } else {
        printf("%s%s%s%s%s", "[GLAControlPlayerInteract] - ", location->get_entities()->get_player()->get_name(),
               " interact with ", location->get_entities()->get_item(item_index)->get_name(), "\n");
        location->get_entities()->get_player()->put_item(location->get_entities()->remove_item(item_index));
      }
    }
  }
};
