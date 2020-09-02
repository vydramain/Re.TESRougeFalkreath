//
// Created by vydra on 15.07.2020.
//

#pragma once

#include "entities/location_entities/LocationsEntity.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/ItemsSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/MagwehrsSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/sub_systems/SentientsSystem.h"

class LocationSystem : public ILocationSystem {
 private:
  const char *name = nullptr;
  bool is_go_to_bloodlet_throne_from_west_forest = false;
  bool is_go_to_west_forest_from_bloodlet_throne_by_hatch = false;
  bool is_go_to_west_forest_from_bloodlet_throne_by_cave = false;
  bool is_go_to_falkreath_from_west_forest = false;
  bool is_go_to_west_forest_from_falkreath = false;
  bool is_story_end = false;

  unsigned int size_x = 0;
  unsigned int size_y = 0;
  EntitiesSystem *entities;

 public:
  explicit LocationSystem();
  explicit LocationSystem(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                          EntitiesSystem *input_entities_system);
  ~LocationSystem() override;

  const char *get_name() const override;

  void set_go_to_bloodlet_throne_from_west_forest(bool input_boolean) override;
  void set_go_to_west_forest_from_bloodlet_throne_by_hatch(bool input_boolean) override;
  void set_go_to_west_forest_from_bloodlet_throne_by_cave(bool input_boolean) override;
  void set_go_to_falkreath_from_west_forest(bool input_boolean) override;
  void set_go_to_west_forest_form_falkreth(bool input_boolean) override;
  void set_story_end(bool input_boolean) override;

  bool get_go_to_bloodlet_throne_from_west_forest() const override;
  bool get_go_to_west_forest_from_bloodlet_throne_by_hatch() const override;
  bool get_go_to_west_forest_from_bloodlet_throne_by_cave() const override;
  bool get_go_to_falkreath_from_west_forest() const override;
  bool get_go_to_west_forest_from_falkreath() const override;
  bool get_story_end() const override;

  unsigned get_size_x() const override;
  unsigned get_size_y() const override;
  EntitiesSystem *get_entities() override;
  EntitiesSystem *get_entities() const override;

  void set_location(const char *input_name, unsigned int input_size_x, unsigned int input_size_y,
                    EntitiesSystem *input_entities_system) override;
};
