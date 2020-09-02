//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems_new/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

class ILocationSystem {
 public:
  virtual ~ILocationSystem() = default;

  virtual const char* get_name() const = 0;

  virtual void set_go_to_bloodlet_throne_from_west_forest(bool input_boolean) = 0;
  virtual void set_go_to_west_forest_from_bloodlet_throne_by_hatch(bool input_boolean) = 0;
  virtual void set_go_to_west_forest_from_bloodlet_throne_by_cave(bool input_boolean) = 0;
  virtual void set_go_to_falkreath_from_west_forest(bool input_boolean) = 0;
  virtual void set_go_to_west_forest_form_falkreth(bool input_boolean) = 0;
  virtual void set_story_end(bool input_boolean) = 0;

  virtual bool get_go_to_bloodlet_throne_from_west_forest() const = 0;
  virtual bool get_go_to_west_forest_from_bloodlet_throne_by_hatch() const = 0;
  virtual bool get_go_to_west_forest_from_bloodlet_throne_by_cave() const = 0;
  virtual bool get_go_to_falkreath_from_west_forest() const = 0;
  virtual bool get_go_to_west_forest_from_falkreath() const = 0;
  virtual bool get_story_end() const = 0;

  virtual unsigned get_size_x() const = 0;
  virtual unsigned get_size_y() const = 0;
  virtual EntitiesSystem *get_entities() = 0;
  virtual EntitiesSystem *get_entities() const = 0;

  virtual void set_location(const char* input_name, unsigned input_size_x, unsigned input_size_y,
                            EntitiesSystem *input_entities_systems) = 0;
};
