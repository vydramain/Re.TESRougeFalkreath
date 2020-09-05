//
// Created by vydra on 9/5/20.
//

#include "systems/scenes_systems/game_loop_systems/load/sub_systems/auto_map_system/AutoMapSystem.hpp"

#include <systems/scenes_systems/game_loop_systems/world/sub_systems/map_systems/MapSystem.hpp>

AutoMapSystem::AutoMapSystem(std::string input_map_name) {
  map_name = std::move(input_map_name);
}

AutoMapSystem::~AutoMapSystem() {
  delete entities_system;
}

IMapSystem *AutoMapSystem::generate_location() {
  srand48(time(nullptr));
  size_x = 300;
  size_y = 150;
  entities_system = new EntitiesSystem();

  unsigned room_x = 3;
  unsigned room_y = 1;
  unsigned last_random;
  generate_entrance(room_x + rand() % 5 + 2, room_y + rand() % 5 + 2);
  generate_random_room(room_x, room_y, rand() % 3);
  unsigned random_count = rand() % 5 + 2;
  for (unsigned i = 0; i < random_count; i++) {
    last_random = generate_random_corridor(room_x, room_y, 1 + rand() % 1);
    generate_random_room(room_x, room_y, rand() % 3, last_random);
    generate_coins(room_x - 2, room_y - 2);
  }
  generate_exit(room_x - rand() % 6 - 2, room_y - rand() % 6 - 2);

  return new MapSystem(map_name, size_x, size_y, entities_system);
}

void AutoMapSystem::generate_small_room(unsigned input_x, unsigned input_y) {
  for (unsigned int i = input_x; i <= input_x + small_room_size_x; i++) {
    entities_system->put_ambient(new Cobblestone(i, input_y));
    entities_system->put_ambient(new Cobblestone(i, input_y + small_room_size_y));
  }
  for (unsigned int j = input_y; j <= input_y + small_room_size_y; j++) {
    entities_system->put_ambient(new Cobblestone(input_x, j));
    entities_system->put_ambient(new Cobblestone(input_x + small_room_size_x, j));
  }
}

void AutoMapSystem::generate_middle_room(unsigned input_x, unsigned input_y) {
  for (unsigned int i = input_x; i <= input_x + middle_room_size_x; i++) {
    entities_system->put_ambient(new Cobblestone(i, input_y));
    entities_system->put_ambient(new Cobblestone(i, input_y + middle_room_size_y));
  }
  for (unsigned int j = input_y; j <= input_y + middle_room_size_y; j++) {
    entities_system->put_ambient(new Cobblestone(input_x, j));
    entities_system->put_ambient(new Cobblestone(input_x + middle_room_size_x, j));
  }
}

void AutoMapSystem::generate_large_room(unsigned input_x, unsigned input_y) {
  for (unsigned int i = input_x; i <= input_x + large_room_size_x; i++) {
    entities_system->put_ambient(new Cobblestone(i, input_y));
    entities_system->put_ambient(new Cobblestone(i, input_y + large_room_size_y));
  }
  for (unsigned int j = input_y; j <= input_y + large_room_size_y; j++) {
    entities_system->put_ambient(new Cobblestone(input_x, j));
    entities_system->put_ambient(new Cobblestone(input_x + large_room_size_x, j));
  }
}

void AutoMapSystem::generate_corridors_horizontal(unsigned input_x, unsigned input_y) {
  clear_entrance_to_corridor_horizon(input_x, input_y);
  for (unsigned int i = input_x; i < input_x + corridor_size_length; i++) {
    entities_system->put_ambient(new Cobblestone(i, input_y));
    entities_system->put_ambient(new Cobblestone(i, input_y + corridor_size_width));
  }
}

void AutoMapSystem::generate_corridors_vertical(unsigned input_x, unsigned input_y) {
  clear_entrance_to_corridor_vertical(input_x, input_y);
  for (unsigned int j = input_y; j < input_y + corridor_size_length; j++) {
    entities_system->put_ambient(new Cobblestone(input_x, j));
    entities_system->put_ambient(new Cobblestone(input_x + corridor_size_width, j));
  }
}

void AutoMapSystem::generate_exit(unsigned input_x, unsigned input_y) {
  entities_system->put_ambient(new CaveQuit(input_x, input_y));
}

void AutoMapSystem::generate_entrance(unsigned int input_x, unsigned int input_y) {
  entities_system->put_ambient(new LowerHatch(input_x, input_y));
}

void AutoMapSystem::generate_coins(unsigned int input_x, unsigned int input_y) {
  auto *randomizer = new AutoLootSystem(entities_system);
  randomizer->generate_group_of_coins(1, input_x, input_y);
}

void AutoMapSystem::generate_random_room(unsigned int &input_x, unsigned int &input_y, unsigned input_random,
                                         unsigned last_random) {
  if (input_random == 0) {
    generate_small_room(input_x, input_y);
    clear_entrance_to_room(input_x, input_y, last_random);
    input_x += small_room_size_x;
    input_y += small_room_size_y;
  }
  if (input_random == 1) {
    generate_middle_room(input_x, input_y);
    clear_entrance_to_room(input_x, input_y, last_random);
    input_x += middle_room_size_x;
    input_y += middle_room_size_y;
  }
  if (input_random == 2) {
    generate_large_room(input_x, input_y);
    clear_entrance_to_room(input_x, input_y, last_random);
    input_x += large_room_size_x;
    input_y += large_room_size_y;
  }
}

unsigned AutoMapSystem::generate_random_corridor(unsigned int &input_x, unsigned int &input_y, unsigned input_random) {
  if (input_random == 1) {
    generate_corridors_horizontal(input_x, input_y - corridor_size_length);
    input_x += corridor_size_length;
    input_y -= 7;
  }
  if (input_random == 2) {
    generate_corridors_vertical(input_x - corridor_size_length, input_y);
    input_x -= 7;
    input_y += corridor_size_length;
  }
  return input_random;
}

void AutoMapSystem::clear_entrance_to_room(unsigned int input_x, unsigned int input_y, unsigned int last_random) {
  if (last_random == 1) {
    entities_system->remove_ambient(entities_system->get_ambient_index(input_x, input_y + 3));
    entities_system->remove_ambient(entities_system->get_ambient_index(input_x, input_y + 4));
  }
  if (last_random == 2) {
    entities_system->remove_ambient(entities_system->get_ambient_index(input_x + 3, input_y));
    entities_system->remove_ambient(entities_system->get_ambient_index(input_x + 4, input_y));
  }
}

void AutoMapSystem::clear_entrance_to_corridor_horizon(unsigned int input_x, unsigned int input_y) {
  entities_system->remove_ambient(entities_system->get_ambient_index(input_x, input_y + 1));
  entities_system->remove_ambient(entities_system->get_ambient_index(input_x, input_y + 2));
}

void AutoMapSystem::clear_entrance_to_corridor_vertical(unsigned int input_x, unsigned int input_y) {
  entities_system->remove_ambient(entities_system->get_ambient_index(input_x + 1, input_y));
  entities_system->remove_ambient(entities_system->get_ambient_index(input_x + 2, input_y));
}