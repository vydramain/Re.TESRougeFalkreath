//
// Created by vydra on 12.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_MAIN_MENU_RENDER_H_
#define INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_MAIN_MENU_RENDER_H_

#include "./BearLibTerminal.h"
#include "ecs/systems//render_system/interface_render.h"

class main_menu_render : public interface_render {
 private:
  static const unsigned SCREENMODE_X = 28;
  static const unsigned SCREENMODE_Y = 17;

 public:
  main_menu_render();

  ~main_menu_render();

  void clear_all();
  void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);
  void view_choice(const char *title, const char **input_choices, unsigned input_count_choices,
                   unsigned highlighted_choice, unsigned in_x = 0, unsigned in_y = 0, unsigned out_x = SCREENMODE_X - 1,
                   unsigned out_y = SCREENMODE_Y - 1);

  void render();
};

#endif  // INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_MAIN_MENU_RENDER_H_
