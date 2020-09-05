//
// Created by vydra on 9/2/20.
//

#pragma once

#include <vector>

#include "systems/scenes_systems/game_loop_systems/load/SectionalLoadSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"
#include "systems/scenes_systems/game_loop_systems/load/sub_systems/auto_map_system/AutoMapSystem.hpp"

class WorldSystem : public IWorldSystem {
 private:
  bool ending = false;
  std::vector<IMapSystem*> maps;
  IMapSystem* current_map = nullptr;

 public:
  explicit WorldSystem();
  ~WorldSystem() override;

  void add_new_map(std::string input_map_address) override;
  void add_rnd_map(std::string input_map_name) override;
  void add_old_map(std::string input_map_address) override;
  void set_current_map(std::string input_name) override;
  void set_ending_game(bool input_ending) override;

  bool get_ending_game() override;
  IMapSystem* get_current_map() override;
  IMapSystem* get_current_map() const override;
  std::vector<std::string>* get_maps_names() override;
};