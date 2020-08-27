//
// Created by vydra on 8/17/20.
//

#include "entities/scenes_entities/game_loop_scene/sub_scenes/EndingScene.hpp"

EndingScene::EndingScene(LocationSystem* input_location, MenuData *input_ending_data)
    : IScene("EndingScene") {
  gle_input = new GLEControls(input_location, input_ending_data);
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
