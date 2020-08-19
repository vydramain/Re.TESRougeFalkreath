//
// Created by vydra on 7/31/20.
//

#pragma once

#include <map>

#include "systems/controls_systems/global_controls/GControlExit.h"
#include "systems/controls_systems/global_controls/GControlMainMenu.h"
#include "systems/controls_systems/global_controls/GControlNewGame.h"
#include "systems/controls_systems/global_controls/GControlScoreList.hpp"

class GControlMap {
 private:
  GControlExit *exit = nullptr;
  GControlMainMenu *main_menu = nullptr;
  GControlNewGame *new_game = nullptr;
  GControlScoreList *score_list = nullptr;

  std::map<unsigned, IControl *> main_map;
  std::map<unsigned, IControl *>::iterator main_iterator;

  IRenderSystem *render = nullptr;
  unsigned *last_highlighted = nullptr;

 public:
  explicit GControlMap() {
    printf("%s", "[GControlMap] - Launch BearLibTerminal's render system\n");
    render = new BearRenderSystem();
    last_highlighted = new unsigned(0);

    printf("%s", "[GControlMap] - Creating global controls\n");
    exit = new GControlExit();
    main_menu = new GControlMainMenu(render, last_highlighted);
    new_game = new GControlNewGame(render, last_highlighted);
    score_list = new GControlScoreList(render, last_highlighted);

    main_map[0] = main_menu;
    main_map[1] = new_game;
    main_map[2] = score_list;
    main_map[3] = exit;
  }

  ~GControlMap() {
    printf("%s", "[GControlMap] - Deleting global controls\n");
    main_map.clear();

    delete exit;
    delete main_menu;
    delete new_game;
    delete score_list;

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
