//
// Created by vydra on 9/4/20.
//

#include "systems_new/scenes_systems/game_loop_systems/load/SectionalLoadSystem.hpp"

bool SectionalLoadSystem::check_file() {
  return map_reader->is_file() && ambient_reader->is_file() && item_reader->is_file();
}

void SectionalLoadSystem::clear_fields() {
  delete map_reader;
  delete ambient_reader;
  delete item_reader;
  delete entities_system;
}

void SectionalLoadSystem::complete_entities_ambient() {
  if (entities_system != nullptr) {
    auto *i = new unsigned(0);
    auto *j = new unsigned(0);
    IControl *control;
    auto *map = new LControlMap(i, j, entities_system);

    for (*j = 0; *j < map_reader->get_map_size_y(); *j = *j + 1) {
      for (*i = 0; *i < map_reader->get_map_size_x(); *i = *i + 1) {
        control = map->get_control(ambient_reader->get_char());
        control->execute();
        if (check_file()) {
          clear_fields();
          delete entities_system;
          entities_system = nullptr;
          delete i;
          delete j;
          delete map;
          return;
        }
      }
    }
    delete i;
    delete j;
    delete map;
  }
}

void SectionalLoadSystem::complete_entities_item() {}

void SectionalLoadSystem::complete_entities_random_item() {}

void SectionalLoadSystem::create_entities_system() {
  PseudoLogSystem::log("SectionalLoadSystem", "Creating and completion entities system");
  entities_system = new EntitiesSystem();
  auto *i = new unsigned(0);
  auto *j = new unsigned(0);
  IControl *control;
  auto *map = new LControlMap(i, j, entities_system);

  for (*j = 0; *j < map_reader->get_map_size_y(); *j = *j + 1) {
    for (*i = 0; *i < map_reader->get_map_size_x(); *i = *i + 1) {
      control = map->get_control(ambient_reader->get_char());
      control->execute();
      if (check_file()) {
        clear_fields();
        delete entities_system;
        entities_system = nullptr;
        delete i;
        delete j;
        delete map;
        return;
      }
    }
  }

  delete i;
  delete j;
  delete map;
}

SectionalLoadSystem::SectionalLoadSystem(std::string input_map_address) {
  map_reader = new MapTitleReader(input_map_address.append("/Title.bin"));
  ambient_reader = new MapAmbientReader(input_map_address.append("/Ambient.bin"));
  item_reader = new MapItemReader(input_map_address.append("/Item.bin"));
}

SectionalLoadSystem::~SectionalLoadSystem() {
  clear_fields();
}

void SectionalLoadSystem::load_map() {
  if (map_reader && ambient_reader && item_reader) {
    if (map_reader->open() && ambient_reader->open() && item_reader->open()) {
      PseudoLogSystem::log("SectionalLoadSystem", "Map", map_reader->get_file_name().data(), "found");
    } else {
      PseudoLogSystem::log("SectionalLoadSystem", "Map", map_reader->get_file_name().data(), "found");
      return;
    }
  }
  PseudoLogSystem::log("SectionalLoadSystem", "Readers not set up");
  delete entities_system;
}

std::string SectionalLoadSystem::get_map_name() const {
  return map_reader->get_map_name();
}

unsigned SectionalLoadSystem::get_location_size_x() const {
  return map_reader->get_map_size_x();
}

unsigned SectionalLoadSystem::get_location_size_y() const {
  return map_reader->get_map_size_y();
}

EntitiesSystem *SectionalLoadSystem::get_entities_system() const {
  return entities_system;
}

IMapSystem *SectionalLoadSystem::get_map_system() const {
  return new MapSystem(get_map_name(), get_location_size_x(), get_location_size_y(), get_entities_system());
}
