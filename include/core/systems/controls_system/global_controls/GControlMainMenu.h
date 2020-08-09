//
// Created by vydra on 8/9/20.
//

#pragma once

#include "core/entities/scenes_entities/main_menu_scene/MainMenuScene.h"
#include "core/systems/controls_system/IControl.h"

class GControlMainMenu : public IControl {
 private:
  unsigned *highlighted;

 public:
  explicit GControlMainMenu(unsigned *input_pointer) : IControl("GControlMainMenu"), highlighted(input_pointer) {}
  ~GControlMainMenu() override = default;

  void execute() override {
    auto *main_scene = new MainMenuScene();
    main_scene->run();
    *highlighted = main_scene->get_highlighted();
    delete main_scene;
  }
};
