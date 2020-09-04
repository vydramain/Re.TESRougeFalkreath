//
// Created by vydra on 8/24/20.
//

#pragma once

#include "IGLControl.h"
#include "systems/controls_systems/IControl.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/ILocationSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"
#include "systems_new/scenes_systems/game_loop_systems/load/LoadSystem.h"

class GLControlLocationChange : public IGLControl {
 private:
  unsigned int x = 0;
  unsigned int y = 0;

  const char* locations_name = nullptr;
  const char* locations_file_name = nullptr;
  ILocationSystem* location_system = nullptr;
  IRenderSystem* render_system = nullptr;

 public:
  explicit GLControlLocationChange(IRenderSystem* input_render_system, LocationSystem* input_location_system,
                                   const char* input_locations_name, const char* input_locations_file_name,
                                   unsigned int input_x, unsigned int input_y)
      : IGLControl("GLControlLocationChange") {
    x = input_x;
    y = input_y;

    locations_name = input_locations_name;
    locations_file_name = input_locations_file_name;
    location_system = input_location_system;
    render_system = input_render_system;
  }
  ~GLControlLocationChange() override {
    location_system = nullptr;
  }

  IControl* get_last_executed_control() override {
    return this;
  }

  void execute() override {
    Sentient* player = new Sentient(*location_system->get_entities()->get_player());
    player->set_current_x(x);
    player->set_current_y(y);

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
    location_system->get_entities()->put_player(player);
    render_system->set_pseudo_game_loop_render();

    delete load_system;
  }
};
