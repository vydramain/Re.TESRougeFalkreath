//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/items_entities/Coin.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class LControlCoin : public ILControl {
 public:
  explicit LControlCoin(unsigned *input_x, unsigned *input_y, EntitiesSystem *input_entities_system)
      : ILControl("LControlCoin", input_x, input_y, input_entities_system) {}
  ~LControlCoin() override = default;

  void execute() override {
    entities_system->put_item(new Coin(*new_x, *new_y));
  }
};