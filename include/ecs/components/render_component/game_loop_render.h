//
// Created by vydra on 14.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GAME_LOOP_RENDER_H
#define RE_TESROUGEFALKREATH_GAME_LOOP_RENDER_H

#include "ecs/components/render_component/interface_render.h"
#include "ecs/entities/creatures_entities/creatures_entity.h"
#include "ecs/entities/locations_entities/location_entity.h"

class game_loop_render : public interface_render {
private:
    static const int SCREENMODE_X = 100;
    static const int SCREENMODE_Y = 40;

    static const int world_edge_x = SCREENMODE_X - 34;
    static const int world_edge_y = SCREENMODE_Y;

    const location_entity *location = nullptr;
    const creatures_entity *creatures = nullptr;

    const creature_entity *target = nullptr;
    unsigned int last_x;
    unsigned int last_y;

public:

    explicit game_loop_render(const location_entity *input_location, const creatures_entity *input_creatures);
    ~game_loop_render() override;

    void set_target_creature(const creature_entity *input_target);

    void clear_all() override;
    void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) override;

    void view_message(const char *input_first_string, const char *input_second_string, unsigned in_x, unsigned in_y,
                      unsigned out_x, unsigned out_y);
//    char *view_request_word(const char *input_request_string, unsigned request_word_size, unsigned return_word_size,
//                            unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);
    void view_choice(const char *title, const char **input_choices, unsigned input_count_choices,
                     unsigned highlighted_choice,
                     unsigned in_x = 0, unsigned in_y = 0,
                     unsigned out_x = SCREENMODE_X - 1, unsigned out_y = SCREENMODE_Y - 1);

    unsigned calc_camera_position_x(unsigned input_x);
    unsigned calc_camera_position_y(unsigned input_y);
    void paint_symbol(wchar_t symbol);

    void view_location();
    void view_area(unsigned input_camera_x, unsigned input_camera_y);
    void view_creatures(unsigned input_camera_x, unsigned input_camera_y);
    void view_items(unsigned input_camera_x, unsigned input_camera_y) {}

    void view_hud();
//    void view_log_window();

    void render() override;

};

#endif //RE_TESROUGEFALKREATH_GAME_LOOP_RENDER_H
