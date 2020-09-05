//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>
#include <string>

#include "entities/location_entities/sentients_entities/beastfolks/Khadjiit.h"
#include "systems/render_systems/IRenderSystem.h"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlAdventure.h"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlEmpty.h"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlEnding.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlExit.h"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlLocationChange.hpp"
#include "systems/scenes_systems/game_loop_systems/controls/GLControlScoreSave.hpp"

class GLControlMap {
 private:
  GLControlAdventure *control_adventure = nullptr;
  GLControlEmpty *control_empty = nullptr;
  GLControlEnding *control_ending = nullptr;
  GLControlExit *control_exit = nullptr;
  GLControlScoreSave *control_score = nullptr;

  std::map<const char *, IGLControl *> gl_map;
  std::map<const char *, IGLControl *>::iterator gl_iterator;

  GameSettingsData *settings_data = nullptr;
  IWorldSystem *world_system = nullptr;
  IGLControl *last_control = nullptr;

 public:
  explicit GLControlMap(IRenderSystem *input_render_system, IWorldSystem *input_world_system,
                        ParameterQueryData *input_ending_data, GameSettingsData *input_settings_data) {
    settings_data = input_settings_data;
    world_system = input_world_system;

    PseudoLogSystem::log("GLControlMap", "Creating game loop controls");
    control_adventure = new GLControlAdventure(input_world_system);
    control_empty = new GLControlEmpty();
    control_ending = new GLControlEnding(input_world_system, input_ending_data);
    control_exit = new GLControlExit();
    control_score = new GLControlScoreSave(input_world_system, input_ending_data);

    gl_map["GLAControlExit"] = control_exit;
    gl_map["GLAControlEnding"] = control_ending;
    gl_map["GLEControlSelectExit"] = control_exit;
    gl_map["GLEControlSelectEnter"] = control_score;
  }

  ~GLControlMap() {
    PseudoLogSystem::log("GLControlMap", "Delete game loop controls");
    delete control_adventure;
    delete control_empty;
    delete control_ending;
    delete control_exit;
    delete control_score;
  }

  IGLControl *get_start_control() {
    PseudoLogSystem::log("GLControlMap", "Creating world");
    world_system->add_new_map("../maps/falkreath");
    world_system->add_new_map("../maps/west_forest");
    if (settings_data->get_rouge()) {
      world_system->add_rnd_map("BloodletThrone");
    } else {
      world_system->add_new_map("../maps/bloodlet_throne");
    }
    world_system->set_current_map(std::string("Falkreath"));
    if (world_system->get_current_map() == nullptr) {
      PseudoLogSystem::log("GLControlMap", "Can not start loop");
      return control_exit;
    }
    world_system->get_current_map()->get_entities_system()->put_player(new Khadjiit("player", "K", 0xffEEEEEE, 18, 95));
    last_control = control_adventure;
    return control_adventure;
  }

  IGLControl *get_control(IControl *input_control) {
    for (gl_iterator = gl_map.begin(); gl_iterator != gl_map.end(); gl_iterator++) {
      if (std::strcmp(gl_iterator->first, input_control->get_name()) == 0) {
        last_control = gl_iterator->second;
        return gl_iterator->second;
      }
    }
    if (world_system->get_ending_game()) {
      return control_ending;
    }
    return last_control;
  }
};
