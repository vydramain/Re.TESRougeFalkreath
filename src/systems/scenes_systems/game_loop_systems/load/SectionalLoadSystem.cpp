//
// Created by vydra on 9/4/20.
//

#include "systems/scenes_systems/game_loop_systems/load/SectionalLoadSystem.hpp"

bool SectionalLoadSystem::check_files() {
  return !ambient_reader->is_file() && !item_reader->is_file();
}

void SectionalLoadSystem::clear_fields() {
  delete map_reader;
  delete ambient_reader;
  delete item_reader;
  delete entities_system;
}

bool SectionalLoadSystem::find_map() {
  if (map_reader && ambient_reader && item_reader) {
    if (map_reader->open() && ambient_reader->open() && item_reader->open()) {
      PseudoLogSystem::log("SectionalLoadSystem", "Map", map_reader->get_file_name().data(), "found");
      return true;
    }
  }
  PseudoLogSystem::log("SectionalLoadSystem", "Map", map_reader->get_file_name().data(), "not found");
  return false;
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
        if (check_files()) {
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

void SectionalLoadSystem::complete_entities_item() {
  if (item_reader->has_item()) {
    item_reader->load_item();
    if (std::strcmp(item_reader->get_item_type().data(), "Coins") == 0) {
      for (unsigned i = 0; i < item_reader->get_items_count(); i++) {
        entities_system->put_item(new Coin(item_reader->get_item_x(i), item_reader->get_item_y(i)));
      }
    }
  }
}

void SectionalLoadSystem::complete_entities_random_item() {
  auto *randomizer = new AutoLootSystem(entities_system);
  if (item_reader->has_item()) {
    item_reader->load_item();
    if (std::strcmp(item_reader->get_item_type().data(), "Coins") == 0) {
      for (unsigned i = 0; i < item_reader->get_items_count(); i++) {
        randomizer->generate_group_of_coins(1, item_reader->get_item_x(i), item_reader->get_item_y(i));
      }
    }
  }
  delete randomizer;
}

void SectionalLoadSystem::create_entities_system() {
  PseudoLogSystem::log("SectionalLoadSystem", "Creating and completion entities system");
  entities_system = new EntitiesSystem();
}

SectionalLoadSystem::SectionalLoadSystem(const std::string& input_map_address) {
  map_reader = new MapTitleReader(std::string(input_map_address).append("/Title.bin"));
  ambient_reader = new MapAmbientReader(std::string(input_map_address).append("/Ambient.bin"));
  item_reader = new MapItemReader(std::string(input_map_address).append("/Item.bin"));
}

SectionalLoadSystem::~SectionalLoadSystem() {
  clear_fields();
}

void SectionalLoadSystem::load_new_map() {
  if (find_map()) {
    create_entities_system();
    complete_entities_ambient();
    complete_entities_random_item();
    return;
  }
  PseudoLogSystem::log("SectionalLoadSystem", "Readers not set up");
  delete entities_system;
}

void SectionalLoadSystem::load_old_map() {
  if (find_map()) {
    create_entities_system();
    complete_entities_ambient();
    complete_entities_item();
    return;
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
