//
// Created by vydra on 8/17/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/EndingScene.hpp"

EndingScene::EndingScene(LocationSystem* input_location, const unsigned input_count, unsigned* input_highlighted)
    : IScene("EndingScene") {
  gle_input = new GLEControls(input_location, input_count, input_highlighted);
}

EndingScene::~EndingScene() {
  delete gle_input;
}

IControl* EndingScene::get_last_control() {
  return last_control;
}

void EndingScene::run() {
  last_control = gle_input->update();
  last_control->execute();
}