//
// Created by vydra on 8/16/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/EndingScene.h"

EndingScene::EndingScene(LocationSystem *input_location) : IScene("EndingScene") {
  location = input_location;
}

EndingScene::~EndingScene() {
  location = nullptr;
}

void EndingScene::run() {}
