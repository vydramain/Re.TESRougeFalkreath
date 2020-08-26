//
// Created by vydra on 8/18/20.
//

#include "entities/render_entities/game_loop_render/sub_renders/GameLoopDialogRender.hpp"

GameLoopDialogRender::GameLoopDialogRender(ILocationSystem *input_system, const Sentient *input_target)
    : location_system(input_system), target(input_target) {}

GameLoopDialogRender::~GameLoopDialogRender() {
  location_system = nullptr;
  target = nullptr;
}

void GameLoopDialogRender::update_fields(unsigned int input_screen_x, unsigned int input_screen_y,
                                         unsigned int input_passive_zone_out_x, unsigned int input_passive_zone_out_y,
                                         unsigned int input_active_zone_in_x, unsigned int input_active_zone_in_y,
                                         unsigned int input_active_zone_out_x, unsigned int input_active_zone_out_y,
                                         unsigned int input_camera_position_x, unsigned int input_camera_position_y) {
  SCREENMODE_X = input_screen_x;
  SCREENMODE_Y = input_screen_y;

  passive_zone_out_x = input_passive_zone_out_x;
  passive_zone_out_y = input_passive_zone_out_y;
  active_zone_in_x = input_active_zone_in_x;
  active_zone_in_y = input_active_zone_in_y;
  active_zone_out_x = input_active_zone_out_x;
  active_zone_out_y = input_active_zone_out_y;

  camera_position_x = input_camera_position_x;
  camera_position_y = input_camera_position_y;
}

void GameLoopDialogRender::update_camera(unsigned int input_camera_position_x, unsigned int input_camera_position_y) {
  camera_position_x = input_camera_position_x;
  camera_position_y = input_camera_position_y;
}

void GameLoopDialogRender::set_dialog(const char *input_first_string, const char *input_second_string) {
  first_dialog_string = input_first_string;
  second_dialog_string = input_second_string;
}

void GameLoopDialogRender::set_question(const char *input_question, const char **input_choices,
                                        unsigned int input_count_choices, unsigned int *input_highlighted) {
  question = input_question;
  choices = input_choices;
  count_choices = input_count_choices;
  highlighted = input_highlighted;
}

void GameLoopDialogRender::render_dialog() {}

void GameLoopDialogRender::render_question() {}

void GameLoopDialogRender::render() {}
