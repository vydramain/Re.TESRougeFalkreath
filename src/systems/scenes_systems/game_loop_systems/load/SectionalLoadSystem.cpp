//
// Created by vydra on 9/4/20.
//

#include "systems/scenes_systems/game_loop_systems/load/SectionalLoadSystem.hpp"

#include <string>

bool SectionalLoadSystem::check_files() {
  return !ambient_reader->is_file() && !item_reader->is_file();
}

void SectionalLoadSystem::clear_fields() {
  delete map_name;
  delete map_reader;
  delete ambient_reader;
  delete sentient_reader;
  delete item_reader;
  delete entities_system;
}

bool SectionalLoadSystem::find_map() {
  if (map_reader && ambient_reader && item_reader && sentient_reader) {
    if (map_reader->open() && ambient_reader->open() && item_reader->open() && sentient_reader->open()) {
      PseudoLogSystem::log("SectionalLoadSystem", "Map", map_name->data(), "found");
      return true;
    }
  }
  PseudoLogSystem::log("SectionalLoadSystem", "Map", map_name->data(), "not found");
  return false;
}

void SectionalLoadSystem::complete_entities_ambient() {
  if (entities_system != nullptr) {
    auto *data = new LoadControlsEntitysData();
    IControl *control;
    auto *map = new LControlMap(data, entities_system);

    for (data->set_y(0); data->get_y() < map_reader->get_map_size_y(); data->set_y(data->get_y() + 1)) {
      for (data->set_x(0); data->get_x() < map_reader->get_map_size_x(); data->set_x(data->get_x() + 1)) {
        control = map->get_control(ambient_reader->get_char());
        control->execute();
        if (check_files()) {
          clear_fields();
          delete entities_system;
          entities_system = nullptr;
          delete map;
          return;
        }
      }
    }
    delete map;
  }
}

void SectionalLoadSystem::complete_entities_sentient() {
  while (sentient_reader->has_sentient() && sentient_reader->load_sentient()) {
    if (sentient_reader->get_sentient_name() == "Nord") {
      entities_system->put_sentient(new Nord(sentient_reader->get_sentient_nickname().data(),
                                             sentient_reader->get_sentient_x(), sentient_reader->get_sentient_y()));
    }
    if (sentient_reader->get_sentient_name() == "Khajiit") {
      entities_system->put_sentient(new Khajiit(sentient_reader->get_sentient_nickname().data(),
                                                sentient_reader->get_sentient_x(), sentient_reader->get_sentient_y()));
    }
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

SectionalLoadSystem::SectionalLoadSystem(std::string *input_map_address) {
  map_name = input_map_address;
  auto title = new std::string(*input_map_address);
  auto sentients = new std::string(*input_map_address);
  auto ambients = new std::string(*input_map_address);
  auto items = new std::string(*input_map_address);

  title->append("/Title.bin");
  sentients->append("/Sentients.bin");
  ambients->append("/Ambients.bin");
  items->append("/Items.bin");

  map_reader = new MapTitleReader(title);
  sentient_reader = new MapSentientReader(sentients);
  ambient_reader = new MapAmbientReader(ambients);
  item_reader = new MapItemReader(items);
}

SectionalLoadSystem::~SectionalLoadSystem() {
  clear_fields();
}

void SectionalLoadSystem::load_new_map() {
  if (find_map()) {
    create_entities_system();
    complete_entities_ambient();
    complete_entities_sentient();
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
    complete_entities_sentient();
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
