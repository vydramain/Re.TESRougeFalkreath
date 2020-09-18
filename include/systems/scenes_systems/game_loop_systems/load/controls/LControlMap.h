//
// Created by vydra on 8/14/20.
//

#pragma once

#include <map>

#include "systems/IControl.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ILControl.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/LControlEmpty.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlCaveQuit.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlCobblestone.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlDoor.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlEastGate.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlGlacier.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlHedge.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlLowerHatch.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlPlant.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlRoadbrick.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlSouthGate.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlThrone.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlTree.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlUpperHatch.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlWall.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlWater.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/ambients/LControlWestGate.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/items/LControlCoin.h"
#include "systems/scenes_systems/game_loop_systems/load/controls/sentients//LControlNord.hpp"
#include "systems/scenes_systems/game_loop_systems/load/controls/sentients//LControlKhajiit.hpp"
#include "systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/entities_system/EntitiesSystem.h"

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
  LControlKhajiit *khajiit = nullptr;
  LControlNord *nord = nullptr;

  std::map<unsigned, ILControl *> load_map;
  std::map<unsigned, ILControl *>::iterator load_iterator;

 public:
  explicit LControlMap(LoadControlsEntitysData *input_data, EntitiesSystem *input_entities_system) {
    cave_quit = new LControlCaveQuit(input_data, input_entities_system);
    cobblestone = new LControlCobblestone(input_data, input_entities_system);
    coin = new LControlCoin(input_data, input_entities_system);
    door = new LControlDoor(input_data, input_entities_system);
    east_gate = new LControlEastGate(input_data, input_entities_system);
    glacier = new LControlGlacier(input_data, input_entities_system);
    empty = new LControlEmpty();
    hedge = new LControlHedge(input_data, input_entities_system);
    lower_hatch = new LControlLowerHatch(input_data, input_entities_system);
    plant = new LControlPlant(input_data, input_entities_system);
    brick = new LControlRoadbrick(input_data, input_entities_system);
    south_gate = new LControlSouthGate(input_data, input_entities_system);
    throne = new LControlThrone(input_data, input_entities_system);
    tree = new LControlTree(input_data, input_entities_system);
    upper_hatch = new LControlUpperHatch(input_data, input_entities_system);
    wall = new LControlWall(input_data, input_entities_system);
    water = new LControlWater(input_data, input_entities_system);
    west_gate = new LControlWestGate(input_data, input_entities_system);
    nord = new LControlNord(input_data, input_entities_system);
    khajiit = new LControlKhajiit(input_data, input_entities_system);

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
    load_map['N'] = nord;
    load_map['K'] = khajiit;
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
    delete nord;
    delete khajiit;
  }

  IControl *get_control(unsigned input_symbol) {
    load_iterator = load_map.find(input_symbol);
    if (load_iterator == load_map.end()) {
      return empty;
    }
    return load_iterator->second;
  }
};
