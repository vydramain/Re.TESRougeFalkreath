//
// Created by vydra on 14.07.2020.
//

#ifndef INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_GAME_LOOP_RENDER_H_
#define INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_GAME_LOOP_RENDER_H_

#include <charconv>

#include "./BearLibTerminal.h"
#include "ecs/systems//render_system/interface_render.h"
#include "ecs/systems/location_system/Location.h"

class game_loop_render : public interface_render {
 private:
  static const unsigned SCREENMODE_X = 100;
  static const unsigned SCREENMODE_Y = 40;

  static const unsigned passive_zone_out_x = SCREENMODE_X - 34;
  static const unsigned passive_zone_out_y = SCREENMODE_Y;
  static const unsigned active_zone_in_x = passive_zone_out_x / 4;
  static const unsigned active_zone_in_y = passive_zone_out_y / 4;
  static const unsigned active_zone_out_x = passive_zone_out_x - active_zone_in_x;
  static const unsigned active_zone_out_y = passive_zone_out_y - active_zone_in_y;

  unsigned steps = 0;

  const Location *location = nullptr;
  const Sentient *target = nullptr;

  unsigned int current_camera_x;
  unsigned int current_camera_y;

 public:
  explicit game_loop_render(const Location *input_location, const Creatures *input_creatures);
  ~game_loop_render() override;

  void set_target_creature(const Sentient *input_target);

  void clear_all() override;
  void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) override;

  void view_message(const char *input_first_string, const char *input_second_string, unsigned in_x, unsigned in_y,
                    unsigned out_x, unsigned out_y);
  //    char *view_request_word(const char *input_request_string, unsigned request_word_size, unsigned return_word_size,
  //                            unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);
  void view_choice(const char *title, const char **input_choices, unsigned input_count_choices,
                   unsigned highlighted_choice, unsigned in_x = 0, unsigned in_y = 0, unsigned out_x = SCREENMODE_X - 1,
                   unsigned out_y = SCREENMODE_Y - 1);

  void new_camera_position_x();
  void new_camera_position_y();
  void update_camera_position_x();
  void update_camera_position_y();
  void paint_symbol(wchar_t symbol);

  void render_location();
  void render_area(unsigned input_camera_x, unsigned input_camera_y);
  void render_races(unsigned input_camera_x, unsigned input_camera_y);
  void render_creatures(unsigned input_camera_x, unsigned input_camera_y);
  void render_items(unsigned input_camera_x, unsigned input_camera_y);

  void render_hud();
  //    void view_log_window();

  void render() override;
};

#endif  // INCLUDE_ECS_SYSTEMS_RENDER_SYSTEM_GAME_LOOP_RENDER_H_
