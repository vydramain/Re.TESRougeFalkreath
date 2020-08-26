//
// Created by vydra on 8/14/20.
//

#pragma once

#include <map>

#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/other_controls/load_controls/ILControl.h"
#include "systems/controls_systems/other_controls/load_controls/LControlCaveQuit.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlCobblestone.h"
#include "systems/controls_systems/other_controls/load_controls/LControlCoin.h"
#include "systems/controls_systems/other_controls/load_controls/LControlDoor.h"
#include "systems/controls_systems/other_controls/load_controls/LControlEastGate.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlEmpty.h"
#include "systems/controls_systems/other_controls/load_controls/LControlGlacier.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlHedge.h"
#include "systems/controls_systems/other_controls/load_controls/LControlLowerHatch.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlPlant.h"
#include "systems/controls_systems/other_controls/load_controls/LControlRoadbrick.h"
#include "systems/controls_systems/other_controls/load_controls/LControlSouthGate.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlThrone.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlTree.h"
#include "systems/controls_systems/other_controls/load_controls/LControlUpperHatch.hpp"
#include "systems/controls_systems/other_controls/load_controls/LControlWall.h"
#include "systems/controls_systems/other_controls/load_controls/LControlWater.h"
#include "systems/controls_systems/other_controls/load_controls/LControlWestGate.hpp"
#include "systems/scenes_systems/game_loop_systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlMap {
 private:
  LControlCaveQuit *cave_quit = nullptr;
  LControlCobblestone *cobblestone = nullptr;
  LControlCoin *coin = nullptr;
  LControlDoor *door = nullptr;
  LControlEastGate *east_gate = nullptr;
  LControlGlacier *glacier = nullptr;
  LControlEmpty *empty = nullptr;
  LControlHedge *hedge = nullptr;
  LControlLowerHatch *lower_hatch = nullptr;
  LControlPlant *plant = nullptr;
  LControlRoadbrick *brick = nullptr;
  LControlSouthGate *south_gate = nullptr;
  LControlThrone *throne = nullptr;
  LControlTree *tree = nullptr;
  LControlUpperHatch *upper_hatch = nullptr;
  LControlWall *wall = nullptr;
  LControlWater *water = nullptr;
  LControlWestGate *west_gate = nullptr;

  std::map<unsigned, ILControl *> load_map;
  std::map<unsigned, ILControl *>::iterator load_iterator;

 public:
  explicit LControlMap(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system) {
    cave_quit = new LControlCaveQuit(input_x, input_y, input_entities_system);
    cobblestone = new LControlCobblestone(input_x, input_y, input_entities_system);
    coin = new LControlCoin(input_x, input_y, input_entities_system);
    door = new LControlDoor(input_x, input_y, input_entities_system);
    east_gate = new LControlEastGate(input_x, input_y, input_entities_system);
    glacier = new LControlGlacier(input_x, input_y, input_entities_system);
    empty = new LControlEmpty();
    hedge = new LControlHedge(input_x, input_y, input_entities_system);
    lower_hatch = new LControlLowerHatch(input_x, input_y, input_entities_system);
    plant = new LControlPlant(input_x, input_y, input_entities_system);
    brick = new LControlRoadbrick(input_x, input_y, input_entities_system);
    south_gate = new LControlSouthGate(input_x, input_y, input_entities_system);
    throne = new LControlThrone(input_x, input_y, input_entities_system);
    tree = new LControlTree(input_x, input_y, input_entities_system);
    upper_hatch = new LControlUpperHatch(input_x, input_y, input_entities_system);
    wall = new LControlWall(input_x, input_y, input_entities_system);
    water = new LControlWater(input_x, input_y, input_entities_system);
    west_gate = new LControlWestGate(input_x, input_y, input_entities_system);

    load_map['9'] = cave_quit;
    load_map['c'] = cobblestone;
    load_map['$'] = coin;
    load_map['d'] = door;
    load_map['E'] = east_gate;
    load_map['g'] = glacier;
    load_map['L'] = lower_hatch;
    load_map['h'] = hedge;
    load_map['p'] = plant;
    load_map['.'] = brick;
    load_map['Q'] = south_gate;
    load_map['T'] = throne;
    load_map['t'] = tree;
    load_map['U'] = upper_hatch;
    load_map['#'] = wall;
    load_map['~'] = water;
    load_map['W'] = west_gate;
  }

  ~LControlMap() {
    delete cobblestone;
    delete coin;
    delete door;
    delete empty;
    delete lower_hatch;
    delete hedge;
    delete plant;
    delete brick;
    delete south_gate;
    delete tree;
    delete upper_hatch;
    delete wall;
    delete water;
    delete west_gate;
  }

  IControl *get_control(unsigned input_symbol) {
    load_iterator = load_map.find(input_symbol);
    if (load_iterator == load_map.end()) {
      return empty;
    }
    return load_iterator->second;
  }
};