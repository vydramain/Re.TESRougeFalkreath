//
// Created by vydra on 8/9/20.
//

#pragma once

#include "entities/location_entities/ambient_entities/Wall.h"
#include "entities/location_entities/items_entities/Coin.h"
#include "entities/location_entities/sentients_entities/beastfolks/Khadjiit.h"
#include "entities/scenes_entities/game_loop_scene/GameLoopScene.h"
#include "systems/controls_systems/IControl.h"
#include "systems/load_systems/LoadSystem.h"
#include "systems/location_systems/sub_systems/entities_system/ItemsSystem.h"
#include "systems/location_systems/sub_systems/entities_system/MagwehrsSystem.h"
#include "systems/location_systems/sub_systems/entities_system/SentientsSystem.h"
#include "systems/pseudo_log_systems/PseudoLogSystem.hpp"

class LauncherGameLoopScene : public IControl {
 private:
  IRenderSystem *render_system;
  unsigned *highlighted;

 public:
  explicit LauncherGameLoopScene(IRenderSystem *input_system, unsigned *input_pointer);
  ~LauncherGameLoopScene() override;

  void execute() override;
};
