//
// Created by vydra on 8/14/20.
//

#pragma once

#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class ILocationSystem {
 public:
  virtual ~ILocationSystem() = default;

  virtual const char* get_name() const = 0;

  virtual void set_go_to_falkreath(bool input_boolean) = 0;
  virtual void set_go_to_west_forest(bool input_boolean) = 0;
  virtual void set_story_end(bool input_boolean) = 0;

  virtual bool get_go_to_falkreath() const = 0;
  virtual bool get_go_to_west_forest() const = 0;
  virtual bool get_story_end() const = 0;

  virtual unsigned get_size_x() const = 0;
  virtual unsigned get_size_y() const = 0;
  virtual LocationsEntitiesSystem *get_entities() = 0;
  virtual LocationsEntitiesSystem *get_entities() const = 0;

  virtual void set_location(const char* input_name, unsigned input_size_x, unsigned input_size_y,
                            LocationsEntitiesSystem *input_entities_systems) = 0;
};
