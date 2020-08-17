
#include <cstring>

#include "systems/controls_systems/IControl.h"
#include "systems/controls_systems/global_controls/GControlMap.h"

int main() {
  printf("%s", "starting...\n");
  printf("%s", "--------re.TESFalkreath--------\n");
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
