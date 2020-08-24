//
// Created by vydra on 8/24/20.
//

#pragma once

#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/IGLControl.h"
#include "systems/scenes_systems/game_loop_systems/load_systems/LoadSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLControlLocationChange : public IGLControl {
 private:
  const char* locations_name = nullptr;
  const char* locations_file_name = nullptr;
  IControl* adventure_executed_control = nullptr;
  ILocationSystem* location_system = nullptr;

 public:
  explicit GLControlLocationChange(LocationSystem* input_location, const char* input_locations_name,
                                   const char* input_locations_file_name)
      : IGLControl("GLControlLocationChange") {
    locations_name = input_locations_name;
    locations_file_name = input_locations_file_name;
    location_system = input_location;
  }
  ~GLControlLocationChange() override {
    location_system = nullptr;
  }

  IControl* get_last_executed_control() override {
    return adventure_executed_control;
  }

  void execute() override {
    auto* load_system = new LoadSystem(locations_file_name);
    load_system->load_map();
    if (load_system->get_entities_system() == nullptr) {
      PseudoLogSystem::log(get_name(), "Map not found");
      PseudoLogSystem::log(get_name(), "Stop load system");
      delete load_system;
      return;
    }
    location_system->set_location(locations_name, load_system->get_location_size_x(),
                                         load_system->get_location_size_y(), load_system->get_entities_system());
    delete load_system;
  }
};
