//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "entities/location_entities/LocationsEntity.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/ItemsSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/MagwehrsSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/SentientsSystem.h"

class LocationSystem : public ILocationSystem {
 private:
  const char *name = nullptr;
  bool end_of_story = false;

  unsigned int size_x = 0;
  unsigned int size_y = 0;
  LocationsEntitiesSystem *entities;

 public:
  explicit LocationSystem();
  explicit LocationSystem(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                          LocationsEntitiesSystem *input_entities_system);
  ~LocationSystem() override;

  const char *get_name() const override;

  bool is_story_over() override;
  void story_is_over() override;

  unsigned get_size_x() const override;
  unsigned get_size_y() const override;
  LocationsEntitiesSystem *get_entities() override;
  LocationsEntitiesSystem *get_entities() const override;

  void set_location(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                    LocationsEntitiesSystem *input_entities_system) override;
};
