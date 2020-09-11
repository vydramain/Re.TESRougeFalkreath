//
// Created by vydra on 9/11/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopGraficRender.hpp"

GameLoopGraficRender::GameLoopGraficRender(RenderConfigurationData *input_data) {
  data = input_data;

  tiles_map["../sprites/tiny/ambients/glacier.png"] = 0xF000;
  tiles_map["../sprites/tiny/ambients/water.png"] = 0xF001;
  tiles_map["../sprites/tiny/ambients/wall.png"] = 0xF002;
  tiles_map["../sprites/tiny/ambients/tree.png"] = 0xF003;
  tiles_map["../sprites/tiny/ambients/throne.png"] = 0xF004;
  tiles_map["../sprites/tiny/ambients/roadbrick.png"] = 0xF005;
  tiles_map["../sprites/tiny/ambients/plant.png"] = 0xF006;
  tiles_map["../sprites/tiny/ambients/hedge.png"] = 0xF007;
  tiles_map["../sprites/tiny/ambients/hatch.png"] = 0xF008;
  tiles_map["../sprites/tiny/ambients/ground.png"] = 0xF009;
  tiles_map["../sprites/tiny/ambients/gate.png"] = 0xF00A;
  tiles_map["../sprites/tiny/ambients/cobblestone.png"] = 0xF00B;
  tiles_map["../sprites/tiny/ambients/cave_quit.png"] = 0xF00C;
//  tiles_map["../"] = 0xF020;
//  tiles_map["../"] = 0xF040;

  for(auto & it : tiles_map){
    terminal_set(std::to_string(it.second).append(": ").append(it.first).data());
  }
}


void GameLoopGraficRender::render_ambient() {}
void GameLoopGraficRender::render_location_creatures() {}
void GameLoopGraficRender::render_location_items() {}
void GameLoopGraficRender::render() {}
