//
// Created by vydra on 14.07.2020.
//

#ifndef RE_TESROUGEFALKREATH_GAME_LOOP_RENDER_H
#define RE_TESROUGEFALKREATH_GAME_LOOP_RENDER_H

#include "ecs/components/render_component/interface_render.h"

class game_loop_render : public interface_render {
private:
    static const int SCREENMODE_X = 100;
    static const int SCREENMODE_Y = 40;

public:
    static const int world_edge_x = SCREENMODE_X - 34;
    static const int world_edge_y = SCREENMODE_Y;

    explicit game_loop_render();

    ~game_loop_render();

    void clear_all();
    void clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);

    void view_message(const char *input_first_string, const char *input_second_string, unsigned in_x, unsigned in_y,
                      unsigned out_x, unsigned out_y);
//    char *view_request_word(const char *input_request_string, unsigned request_word_size, unsigned return_word_size,
//                            unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y);
    void view_choice(const char *title, const char **input_choices, unsigned input_count_choices,
                     unsigned highlighted_choice,
                     unsigned in_x = 0, unsigned in_y = 0,
                     unsigned out_x = SCREENMODE_X - 1, unsigned out_y = SCREENMODE_Y - 1);

    void paint_symbol(wchar_t symbol);

//    void view_area();
    void view_player();
    void view_hud();
//    void view_log_window();

    void render() override;

};

#endif //RE_TESROUGEFALKREATH_GAME_LOOP_RENDER_H
