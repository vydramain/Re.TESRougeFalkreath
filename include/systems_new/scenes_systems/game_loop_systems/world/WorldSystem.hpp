//
// Created by vydra on 9/2/20.
//

#pragma once

#include <vector>

#include "systems_new/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class WorldSystem : public IWorldSystem {
 private:
  std::vector<IMapSystem*> maps;
  IMapSystem *current_map = nullptr;

 public:
  explicit WorldSystem();
  ~WorldSystem() override;

  void add_world(IMapSystem *input_map_system) override;
  void set_current_map(std::string input_name) override;

  IMapSystem* get_current_map() override;
  IMapSystem* get_current_map() const override;
};