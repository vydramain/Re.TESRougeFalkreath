//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "entities/location_entities/sentients_entities/beastfolks/Khadjiit.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlAdventure.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlEmpty.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlEnding.hpp"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlExit.h"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlLocationChange.hpp"
#include "systems/controls_systems/scenes_controls/game_loop_controls/GLControlScoreSave.hpp"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/game_loop_systems/location_systems/LocationSystem.h"

class GLControlMap {
 private:
  GLControlAdventure *control_adventure = nullptr;
  GLControlEmpty *control_empty = nullptr;
  GLControlEnding *control_ending = nullptr;
  GLControlExit *control_exit = nullptr;
  GLControlLocationChange *control_load_bloodlet_throne_from_west_forest = nullptr;
  GLControlLocationChange *control_load_west_forest_from_bloodlet_throne_by_hatch = nullptr;
  GLControlLocationChange *control_load_west_forest_from_bloodlet_throne_by_cave = nullptr;
  GLControlLocationChange *control_load_falkreath_from_west_forest = nullptr;
  GLControlLocationChange *control_load_west_forest_from_falkreath = nullptr;
  GLControlScoreSave *control_score = nullptr;

  std::map<const char *, IGLControl *> gl_map;
  std::map<const char *, IGLControl *>::iterator gl_iterator;

  ILocationSystem *location_system = nullptr;
  IGLControl *last_control = nullptr;

 public:
  explicit GLControlMap(IRenderSystem *input_render_system, LocationSystem *input_location_system,
                        ParameterQueryData *input_ending_data) {
    location_system = input_location_system;

    printf("%s", "[GLControlMap] - Creating game loop controls\n");
    control_adventure = new GLControlAdventure(input_location_system);
    control_empty = new GLControlEmpty();
    control_ending = new GLControlEnding(input_location_system, input_ending_data);
    control_exit = new GLControlExit();
    control_load_bloodlet_throne_from_west_forest = new GLControlLocationChange(
        input_render_system, input_location_system, "Bloodlet Throne", "../maps/location-system/BloodletThrone-location-system.bin", 5, 3);
    control_load_west_forest_from_bloodlet_throne_by_cave = new GLControlLocationChange(
        input_render_system, input_location_system, "West Forest", "../maps/location-system/WestForest-location-system.bin", 218, 96);
    control_load_west_forest_from_bloodlet_throne_by_hatch = new GLControlLocationChange(
        input_render_system, input_location_system, "West Forest", "../maps/location-system/WestForest-location-system.bin", 181, 95);
    control_load_falkreath_from_west_forest = new GLControlLocationChange(input_render_system, input_location_system,
                                                                          "Falkreath", "../maps/Falkreath.bin", 72, 13);
    control_load_west_forest_from_falkreath = new GLControlLocationChange(
        input_render_system, input_location_system, "West Forest", "../maps/WestForest.bin", 3, 13);
    control_score = new GLControlScoreSave(input_location_system, input_ending_data);

    gl_map["GLAControlExit"] = control_exit;
    gl_map["GLAControlEnding"] = control_ending;
    gl_map["GLAControlGoToWestForest"] = control_load_west_forest_from_falkreath;
    gl_map["GLAControlGoToFalkreath"] = control_load_falkreath_from_west_forest;
    gl_map["GLEControlSelectExit"] = control_exit;
    gl_map["GLEControlSelectEnter"] = control_score;
    gl_map["GLControlLocationChange"] = control_adventure;
  }

  ~GLControlMap() {
    printf("%s", "[GLControlMap] - Delete game loop controls\n");
    delete control_adventure;
    delete control_empty;
    delete control_ending;
    delete control_exit;
    delete control_score;
  }

  IGLControl *get_start_control() {
    PseudoLogSystem::log("GLControlMap", "Load start map");
    auto *load_system = new LoadSystem("../maps/Falkreath.bin");
    load_system->load_map();
    if (load_system->get_entities_system() == nullptr) {
      PseudoLogSystem::log("GLControlMap", "Map not found");
      PseudoLogSystem::log("GLControlMap", "Stop load system");
      delete load_system;
      return control_exit;
    }
    location_system->set_location("Falkreath", load_system->get_location_size_x(), load_system->get_location_size_y(),
                                  load_system->get_entities_system());
    location_system->get_entities()->put_player(new Khadjiit("player", "K", 0xffEEEEEE, 18, 95));
    last_control = control_adventure;
    delete load_system;
    return control_adventure;
  }

  IGLControl *get_control(IControl *input_control) {
    for (gl_iterator = gl_map.begin(); gl_iterator != gl_map.end(); gl_iterator++) {
      if (std::strcmp(gl_iterator->first, input_control->get_name()) == 0) {
        last_control = gl_iterator->second;
        return gl_iterator->second;
      }
    }
    if (location_system->get_story_end()) {
      return control_ending;
    }
    if (location_system->get_go_to_west_forest_from_falkreath()) {
      location_system->set_go_to_west_forest_form_falkreth(false);
      return control_load_west_forest_from_falkreath;
    }
    if (location_system->get_go_to_falkreath_from_west_forest()) {
      location_system->set_go_to_falkreath_from_west_forest(false);
      return control_load_falkreath_from_west_forest;
    }
    if (location_system->get_go_to_bloodlet_throne_from_west_forest()) {
      location_system->set_go_to_bloodlet_throne_from_west_forest(false);
      return control_load_bloodlet_throne_from_west_forest;
    }
    if (location_system->get_go_to_west_forest_from_bloodlet_throne_by_hatch()) {
      location_system->set_go_to_west_forest_from_bloodlet_throne_by_hatch(false);
      return control_load_west_forest_from_bloodlet_throne_by_hatch;
    }
    if (location_system->get_go_to_west_forest_from_bloodlet_throne_by_cave()) {
      location_system->set_go_to_west_forest_from_bloodlet_throne_by_cave(false);
      return control_load_west_forest_from_bloodlet_throne_by_cave;
    }
    return last_control;
  }
};
