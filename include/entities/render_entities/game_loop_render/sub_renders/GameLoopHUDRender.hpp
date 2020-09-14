//
// Created by vydra on 8/17/20.
//

#pragma once

#include <cstring>

#include "./BearLibTerminal.h"
#include "entities/location_entities/sentients_entities/Sentient.h"
#include "entities/render_entities/CleanerRender.h"
#include "entities/render_entities/IRender.h"
#include "entities/render_entities/TextPanelsRender.h"
#include "systems/launcher_system/data/RenderConfigurationData.hpp"
#include "systems/scenes_systems/game_loop_systems/world/IWorldSystem.hpp"

class GameLoopHUDRender : public IRender {
 private:
  RenderConfigurationData *data = nullptr;

  void render_parameter(std::string input_string, unsigned int input_parameter, unsigned int input_x,
                        unsigned int input_y);

 public:
  explicit GameLoopHUDRender(RenderConfigurationData *input_data);
  ~GameLoopHUDRender() override;

  std::vector<std::string *> *prepare_string_message(std::string *input_text) const;
  void view_string_message(std::vector<std::string *> *input_text);
  void produce_string_message(std::string *input_text);

  void check_item_interact(unsigned input_index);
  void check_ambient_interact(unsigned input_index);

  void render_borders();
  void render_nameplate();
  void render_inventory();
  void render_coordinates();
  void render_interact_ability();

  void render() override;
};
