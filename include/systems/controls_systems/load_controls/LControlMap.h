//
// Created by vydra on 8/14/20.
//

#pragma once

#include <map>

#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/load_controls/ILControl.h"
#include "systems/controls_systems/load_controls/LControlCobblestone.h"
#include "systems/controls_systems/load_controls/LControlCoin.h"
#include "systems/controls_systems/load_controls/LControlDoor.h"
#include "systems/controls_systems/load_controls/LControlEmpty.h"
#include "systems/controls_systems/load_controls/LControlHedge.h"
#include "systems/controls_systems/load_controls/LControlPlant.h"
#include "systems/controls_systems/load_controls/LControlRoadbrick.h"
#include "systems/controls_systems/load_controls/LControlSouthGate.hpp"
#include "systems/controls_systems/load_controls/LControlTree.h"
#include "systems/controls_systems/load_controls/LControlWall.h"
#include "systems/controls_systems/load_controls/LControlWater.h"
#include "systems/location_systems/sub_systems/entities_system/LocationsEntitiesSystem.h"

class LControlMap {
 private:
  LControlCobblestone *cobblestone = nullptr;
  LControlCoin *coin = nullptr;
  LControlDoor *door = nullptr;
  LControlEmpty *empty = nullptr;
  LControlHedge *hedge = nullptr;
  LControlPlant *plant = nullptr;
  LControlRoadbrick *brick = nullptr;
  LControlSouthGate *south_gate = nullptr;
  LControlTree *tree = nullptr;
  LControlWall *wall = nullptr;
  LControlWater *water = nullptr;

  std::map<unsigned, ILControl *> load_map;
  std::map<unsigned, ILControl *>::iterator load_iterator;

 public:
  explicit LControlMap(unsigned *input_x, unsigned *input_y, LocationsEntitiesSystem *input_entities_system) {
    cobblestone = new LControlCobblestone(input_x, input_y, input_entities_system);
    coin = new LControlCoin(input_x, input_y, input_entities_system);
    door = new LControlDoor(input_x, input_y, input_entities_system);
    empty = new LControlEmpty();
    hedge = new LControlHedge(input_x, input_y, input_entities_system);
    plant = new LControlPlant(input_x, input_y, input_entities_system);
    brick = new LControlRoadbrick(input_x, input_y, input_entities_system);
    south_gate = new LControlSouthGate(input_x, input_y, input_entities_system);
    tree = new LControlTree(input_x, input_y, input_entities_system);
    wall = new LControlWall(input_x, input_y, input_entities_system);
    water = new LControlWater(input_x, input_y, input_entities_system);

    load_map['c'] = cobblestone;
    load_map['$'] = coin;
    load_map['d'] = door;
    load_map['h'] = hedge;
    load_map['p'] = plant;
    load_map['.'] = brick;
    load_map['q'] = south_gate;
    load_map['t'] = tree;
    load_map['#'] = wall;
    load_map['~'] = water;
  }

  ~LControlMap() {
    delete cobblestone;
    delete coin;
    delete door;
    delete empty;
    delete hedge;
    delete plant;
    delete brick;
    delete south_gate;
    delete tree;
    delete wall;
    delete water;
  }

  IControl *get_control(unsigned input_symbol) {
    load_iterator = load_map.find(input_symbol);
    if (load_iterator == load_map.end()) {
      return empty;
    }
    return load_iterator->second;
  }
};