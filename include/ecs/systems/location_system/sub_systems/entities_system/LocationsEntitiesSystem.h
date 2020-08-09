//
// Created by vydra on 8/10/20.
//

#pragma once

#include <vector>

class LocationsEntitesSystem : public SentientsSystem, public MagwehrsSystem, public ItemsSystem {
 private:
  std::vector<LocationsEntity> entities;

 public:
  explicit LocationsEntitesSystem(unsigned input_count);
  ~LocationsEntitesSystem();

  void put_players_entity(LocationEntity *input_player);
  LocationsEntitesSystem *remove_players_entity();

  void put_entity(LocationEntity *input_enity);
  Sentient *remove_entity(unsigned input_index);

  Sentient *get_players_entity();
  Sentient *get_entity(unsigned input_index);

  unsigned get_size() const;
  const LocationsEntity *get_player() const;
  const LocationsEntity *get_entity(unsigned input_index) const;
};
