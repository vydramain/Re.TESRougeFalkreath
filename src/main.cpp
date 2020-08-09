

#include <cstring>

#include "adds/CCMech.h"
#include "core/systems/controls_system/IControl.h"
#include "core/systems/controls_system/global_controls/GControlMap.h"

int main() {
  auto *main_map = new GControlMap();
  IControl *main_control;

  do {
    main_control = main_map->get_control(main_map->get_highlighted());
    main_control->execute();
  } while (std::strcmp(main_control->get_name(), "GControlExit") != 0);

  delete main_map;

  return 0;
}
