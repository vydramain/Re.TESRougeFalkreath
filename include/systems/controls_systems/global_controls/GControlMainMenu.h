//
// Created by vydra on 8/9/20.
//

#pragma once

#include "entities/scenes_entities/main_menu_scene/MainMenuScene.h"
#include "systems/controls_systems/IControl.h"

class GControlMainMenu : public IControl {
 private:
  IRenderSystem *render_system;
  unsigned *highlighted;

 public:
  explicit GControlMainMenu(IRenderSystem *input_system, unsigned *input_pointer)
      : IControl("GControlMainMenu"), render_system(input_system), highlighted(input_pointer) {}
  ~GControlMainMenu() override = default;

  void execute() override {
    printf("%s", "[GControlMainMenu] - execute main menu control\n");
    auto *main_scene = new MainMenuScene(render_system);
    main_scene->run();
    *highlighted = main_scene->get_highlighted();
    delete main_scene;
  }
};
