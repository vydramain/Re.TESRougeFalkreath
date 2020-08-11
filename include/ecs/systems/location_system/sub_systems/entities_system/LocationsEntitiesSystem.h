//
// Created by vydra on 8/10/20.
//

#pragma once

#include <vector>

#include "adds/CCMech.h"
#include "ecs/systems/location_system/sub_systems/entities_system/ItemsSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/MagwehrsSystem.h"
#include "ecs/systems/location_system/sub_systems/entities_system/SentientsSystem.h"

class LocationsEntitiesSystem : public SentientsSystem, public MagwehrsSystem, public ItemsSystem {
 private:
  std::vector<LocationsEntity> entities;

 public:
  explicit LocationsEntitiesSystem();
  LocationsEntitiesSystem(const LocationsEntitiesSystem &input_data);
  ~LocationsEntitiesSystem() override;

  void put_item(Item *input_entity) override;
  void put_magwehr(Magwehr *input_entity) override;
  void put_player(Sentient *input_entity) override;
  void put_sentient(Sentient *input_entity) override;

  Item *remove_item(unsigned input_index) override;
  Magwehr *remove_magwehr(unsigned input_index) override;
  Sentient *remove_player() override;
  Sentient *remove_sentient(unsigned input_index) override;

  LocationsEntity *get_entity(unsigned input_index);
  const LocationsEntity *get_entity(unsigned input_index) const;
};
