
#include <core/systems/controls_system/load_control/LControlMap.h>

#include <cstring>

#include "core/systems/controls_system/IControl.h"
#include "core/systems/controls_system/global_controls/GControlMap.h"
#include "core/systems/render_system/RenderSystem.h"

int main() {
  auto *main_map = new GControlMap();
  IControl *main_control;

  main_control = main_map->get_control(main_map->get_highlighted());
  do {
    main_control->execute();
    main_control = main_map->get_control(main_map->get_highlighted());
  } while (std::strcmp(main_control->get_name(), "GControlExit") != 0);

  delete main_map;

  return 0;
}
