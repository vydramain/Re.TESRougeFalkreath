//
// Created by vydra on 8/14/20.
//

#pragma once

#include "entities/location_entities/items_entities/Coin.h"
#include "systems/controls_systems/load_controls/ILControl.h"
#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlCoin : public ILControl {
 public:
  explicit LControlCoin(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system)
      : ILControl("LControlCoin", input_x, input_y, input_entities_system) {}
  ~LControlCoin() override = default;

  void execute() override {
    entities_system->put_item(new Coin(*new_x, *new_y));
  }
};
