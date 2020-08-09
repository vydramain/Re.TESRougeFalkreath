//
// Created by vydra on 15.07.2020.
//

#include "ecs/systems/render_system/game_loop_render.h"

game_loop_render::game_loop_render(const Location *input_location, const Creatures *input_creatures) {
  terminal_open();
  terminal_set("window: title='re.TESFalkreath', cellsize=8x15, size=100x40, fullscreen=true;");
  terminal_layer(0);
  terminal_clear();
  terminal_refresh();

  location = input_location;

  target = location->get_races()->get_player();

  new_camera_position_x();
  new_camera_position_y();
}

game_loop_render::~game_loop_render() {
  terminal_clear();
  terminal_close();

  location = nullptr;
}

void game_loop_render::set_target_creature(const Sentient *input_target) {
  target = input_target;
}

void game_loop_render::clear_all() {
  terminal_clear();
}

void game_loop_render::clear_area(unsigned in_x, unsigned in_y, unsigned out_x, unsigned out_y) {
  terminal_clear_area(in_x, in_y, out_x, out_y);
}

void game_loop_render::view_message(const char *input_first_string, const char *input_second_string, unsigned in_x,
                                    unsigned in_y, unsigned out_x, unsigned out_y) {
  // cleaning up Area for message
  for (unsigned j = 0; j < out_y - in_y; j++) {
    for (unsigned i = 0; i < out_x - in_x; i++) {
      terminal_put(in_x + i, in_y + j, ' ');
    }
  }

  // draw borders
  for (unsigned j = 0; j < out_y - in_y; j++) {
    terminal_put(in_x, in_y + j + 1, '|');
    terminal_put(out_x, in_y + j, '|');
  }
  for (unsigned i = 0; i < out_x - in_x; i++) {
    terminal_put(in_x + i, in_y, '-');
    terminal_put(in_x + i + 1, out_y, '-');
  }

  terminal_print(in_x + 2, in_y + 2, input_first_string);
  terminal_print(in_x + 2, in_y + 3, input_second_string);
}

void game_loop_render::view_choice(const char *title, const char **input_choices, unsigned input_count_choices,
                                   unsigned highlighted_choice, unsigned in_x, unsigned in_y, unsigned out_x,
                                   unsigned out_y) {
  for (unsigned ii(0); ii < (out_y - in_y); ii++) {
    for (unsigned i(0); i < (out_x - in_x); i++) {
      terminal_put(in_x + i, in_y + ii, ' ');
    }
  }

  for (unsigned ii(0); ii < (out_y - in_y); ii++) {
    terminal_put(in_x, in_y + 1 + ii, '|');
    terminal_put(out_x, in_y + ii, '|');
  }
  for (unsigned i(0); i < (out_x - in_x); i++) {
    terminal_put(in_x + i, in_y, '-');
    terminal_put(in_x + 1 + i, out_y, '-');
  }

  terminal_print(in_x + 7, in_y + 2, title);
  for (unsigned i(1); i < input_count_choices + 1; i++) {
    if (highlighted_choice == i) {
      terminal_print(in_x + 3, in_y + 3 + i, "-->");
    }
    terminal_print(in_x + 7, in_y + 3 + i, input_choices[i - 1]);
  }
}

void game_loop_render::new_camera_position_x() {
  current_camera_x = target->get_current_x() - active_zone_in_x;
  if (target->get_current_x() < active_zone_in_x) {
    current_camera_x = 0;
  }
  if (location->get_area()->get_size_x() - target->get_current_x() < active_zone_out_x) {
    current_camera_x = location->get_area()->get_size_x() - passive_zone_out_x;
  }
}

void game_loop_render::new_camera_position_y() {
  current_camera_y = target->get_current_y() - active_zone_in_y;
  if (target->get_current_y() < active_zone_in_y) {
    current_camera_y = 0;
  }
  if (location->get_area()->get_size_y() - target->get_current_y() < active_zone_out_y) {
    current_camera_y = location->get_area()->get_size_y() - passive_zone_out_y;
  }
}

void game_loop_render::update_camera_position_x() {
  unsigned target_x = target->get_current_x();

  if (target_x < current_camera_x + active_zone_in_x || target_x > current_camera_x + active_zone_out_x) {
    if (target_x < current_camera_x + active_zone_in_x) {
      current_camera_x = target_x - active_zone_in_x;
      if (target_x < active_zone_in_x) {
        current_camera_x = 0;
      }
    }
    if (target_x > current_camera_x + active_zone_out_x) {
      current_camera_x = target_x - active_zone_out_x;
      if (target_x >= location->get_area()->get_size_x() - active_zone_in_x) {
        current_camera_x = location->get_area()->get_size_x() - passive_zone_out_x;
      }
    }
  }
}

void game_loop_render::update_camera_position_y() {
  unsigned target_y = target->get_current_y();

  if (target_y < current_camera_y + active_zone_in_y || target_y > current_camera_y + active_zone_out_y) {
    if (target_y < current_camera_y + active_zone_in_y) {
      current_camera_y = target_y - active_zone_in_y;
      if (target_y < active_zone_in_y) {
        current_camera_y = 0;
      }
    }
    if (target_y > current_camera_y + active_zone_out_y) {
      current_camera_y = target_y - active_zone_out_y;
      if (target_y >= location->get_area()->get_size_y() - active_zone_in_y) {
        current_camera_y = location->get_area()->get_size_y() - passive_zone_out_y;
      }
    }
  }
}

void game_loop_render::paint_symbol(wchar_t symbol) {
  switch (symbol) {
    case '~': {
      terminal_color(0xcc00ffff);
      break;
    }
    case ';':
    case '+':
    case '-':
    case '?':
    case ':':
    case 'J':
    case '`':
    case 'x':
    case '9': {
      terminal_color(0xff26cf26);
      break;
    }
    case '[':
    case ']':
    case '_': {
      terminal_color(0xff7f7f7f);
      break;
    }
    case 'W':
    case 'w':
    case 'V': {
      terminal_color(0xffe3c347);
      break;
    }
    case '"':
    case '|':
    case '=':
    case '>':
    case '^':
    case 'v':
    case '<': {
      terminal_color(0xffba7300);
      break;
    }
    case '#': {
      terminal_color(0xff666666);
      break;
    }
    case 'L': {
      terminal_color(0xffabff00);
      break;
    }
    case 't': {
      terminal_color(0xffb2b2b2);
      break;
    }
    case 'Z': {
      terminal_color(0xff888800);
      break;
    }
    case '$': {
      terminal_color(0xffffff00);
      break;
    }
    case 'Q': {
      terminal_color(0xff44eedd);
      break;
    }
    default: {
      terminal_color(0xff4c4c4c);
      break;
    }
  }
}

void game_loop_render::render_location() {
  if (target) {
    update_camera_position_x();
    update_camera_position_y();

    render_area(current_camera_x, current_camera_y);
    render_races(current_camera_x, current_camera_y);
    render_creatures(current_camera_x, current_camera_y);
    render_items(current_camera_x, current_camera_y);
  } else {
    view_message("target missed!", "", 0, 0, passive_zone_out_x, passive_zone_out_y);
  }
}

void game_loop_render::render_area(unsigned input_camera_x, unsigned input_camera_y) {
  char temp;
  for (unsigned ii = 0; ii < passive_zone_out_y; ii++) {
    for (unsigned i = 0; i < passive_zone_out_x; i++) {
      terminal_color(0xaaffffff);
      terminal_layer(1);
      temp = location->get_area()->get_cell(input_camera_x + i, input_camera_y + ii);
      paint_symbol(temp);
      terminal_put(i, ii, temp);
    }
  }
}

void game_loop_render::render_races(unsigned input_camera_x, unsigned input_camera_y) {
  const Sentient *race;
  for (unsigned i = 0; i < location->get_races()->get_size(); i++) {
    race = location->get_races()->get_race(i);
    unsigned race_x = race->get_current_x();
    unsigned race_y = race->get_current_y();

    if ((race_x >= input_camera_x && race_x < input_camera_x + passive_zone_out_x) &&
        (race_y >= input_camera_y && race_y < input_camera_y + passive_zone_out_y)) {
      terminal_color(0xddFFFFFF);
      terminal_layer(4);
      terminal_put(race_x - input_camera_x, race_y - input_camera_y, 'i');
    }
  }
}

void game_loop_render::render_creatures(unsigned input_camera_x, unsigned input_camera_y) {
  const Magwehr *creature;
  for (unsigned i = 0; i < location->get_creatures()->get_size(); i++) {
    creature = location->get_creatures()->get_creature(i);
    unsigned creature_x = creature->get_current_x();
    unsigned creature_y = creature->get_current_y();

    if ((creature_x >= input_camera_x && creature_x < input_camera_x + passive_zone_out_x) &&
        (creature_y >= input_camera_y && creature_y < input_camera_y + passive_zone_out_y)) {
      terminal_color(0xddFFFFFF);
      terminal_layer(3);
      terminal_put(creature_x - input_camera_x, creature_y - input_camera_y, 'i');
    }
  }
}

void game_loop_render::render_items(unsigned int input_camera_x, unsigned int input_camera_y) {
  const Item *item;
  for (unsigned i = 0; i < location->get_items()->get_size(); i++) {
    item = location->get_items()->get_item(i);
    unsigned item_x = item->get_current_x();
    unsigned item_y = item->get_current_y();

    if ((item_x >= input_camera_x && item_x < input_camera_x + passive_zone_out_x) &&
        (item_y >= input_camera_y && item_y < input_camera_y + passive_zone_out_y)) {
      terminal_color(0xddFFEB00);
      terminal_layer(2);
      terminal_put(item_x - input_camera_x, item_y - input_camera_y, '$');
    }
  }
}

void game_loop_render::render_hud() {
  terminal_layer(5);
  terminal_color(0xffffffff);
  for (unsigned i = 0; i < passive_zone_out_y; i++) {
    terminal_print(passive_zone_out_x, i, "|");
  }

  for (unsigned i = 0; i < SCREENMODE_X - passive_zone_out_x; i++) {
    terminal_print(passive_zone_out_x + i + 1, 9, "_");
    terminal_print(passive_zone_out_x + i + 1, passive_zone_out_y - 5, "_");
  }

  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 6, "Кошель:");
  char wallet[4];
  snprintf(wallet, (size_t) "%u", "%u", location->get_races()->get_player()->get_wallet());
  terminal_print(passive_zone_out_x + 9, passive_zone_out_y - 6, wallet);

  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 3, "Координаты:");
  char x[4], y[4];
  snprintf(x, (size_t) "%u", "%u", location->get_races()->get_player()->get_current_x());
  snprintf(y, (size_t) "%u", "%u", location->get_races()->get_player()->get_current_y());
  terminal_print(passive_zone_out_x + 15, passive_zone_out_y - 3, x);
  terminal_print(passive_zone_out_x + 18, passive_zone_out_y - 3, y);

  char s[4];
  snprintf(s, (size_t) "%u", "%u", steps);
  terminal_print(passive_zone_out_x + 1, passive_zone_out_y - 1, s);

  terminal_print(passive_zone_out_x + 1, 1, "Имя:");
  terminal_print(passive_zone_out_x + 1, 2, "Раса:");
  terminal_print(passive_zone_out_x + 1, 3, "Статус:");

  terminal_color(0xFFFF4444);
  terminal_print(passive_zone_out_x + 1, 4, "ОЗ:");
  terminal_color(0xFF44ff44);
  terminal_print(passive_zone_out_x + 1, 5, "ОД:");
  terminal_color(0xFF6666FF);
  terminal_print(passive_zone_out_x + 1, 6, "OМ:");
}

void game_loop_render::render() {
  clear_all();
  render_location();
  render_hud();
  steps++;
  terminal_refresh();
}
