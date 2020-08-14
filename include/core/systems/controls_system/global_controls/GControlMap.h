//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "core/systems/controls_system/global_controls/GControlMainMenu.h"
#include "core/systems/controls_system/global_controls/GControlNewGame.h"
#include "core/systems/controls_system/global_controls/GControlExit.h"

class GControlMap {
 private:
  GControlMainMenu *main_menu = nullptr;
  GControlNewGame *new_game = nullptr;
  GControlExit *exit = nullptr;

  std::map<unsigned, IControl *> main_map;
  std::map<unsigned, IControl *>::iterator main_iterator;

  RenderSystem *render = nullptr;
  unsigned *last_highlighted = nullptr;

 public:
  explicit GControlMap() {
    render = new RenderSystem();
    last_highlighted = new unsigned(0);

    main_menu = new GControlMainMenu(render, last_highlighted);
    new_game = new GControlNewGame(render, last_highlighted);
    exit = new GControlExit();

    main_map[0] = main_menu;
    main_map[1] = new_game;
    main_map[2] = exit;
  }

  ~GControlMap() {
    main_map.clear();

    delete main_menu;
    delete new_game;
    delete exit;

    delete last_highlighted;
    delete render;
  }

  unsigned get_highlighted() const {
    return *last_highlighted;
  }

  IControl *get_control(unsigned input_highlighted) {
    main_iterator = main_map.find(input_highlighted);
    if (main_iterator == main_map.end()) {
      return exit;
    }
    return main_iterator->second;
  }
};
