//
// Created by vydra on 8/10/20.
//

#pragma once

#include <vector>

#include "adds/CCMech.h"
#include "entities/location_entities/LocationsEntity.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/AmbientsSystem.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/ItemsSystem.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/MagwehrsSystem.h"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/SentientsSystem.h"

class EntitiesSystem : public AmbientsSystem, public ItemsSystem, public MagwehrsSystem, public SentientsSystem {
 private:
  std::vector<LocationsEntity> entities;

 public:
  explicit EntitiesSystem();
  EntitiesSystem(const EntitiesSystem &input_data);
  virtual ~EntitiesSystem();

  void put_ambient(Ambient *input_ambient) override;
  void put_item(Item *input_entity) override;
  void put_magwehr(Magwehr *input_entity) override;
  void put_player(Sentient *input_entity) override;
  void put_sentient(Sentient *input_entity) override;

  Ambient *remove_ambient(unsigned input_index) override;
  Item *remove_item(unsigned input_index) override;
  Magwehr *remove_magwehr(unsigned input_index) override;
  Sentient *remove_player() override;
  Sentient *remove_sentient(unsigned input_index) override;

  LocationsEntity *get_entity(unsigned input_index);
  const LocationsEntity *get_entity(unsigned input_index) const;
};
