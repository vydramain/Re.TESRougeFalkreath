//
// Created by vydra on 8/18/20.
//

#include "systems_new/scenes_systems/statistics_systems/StdStatisticsSystem.hpp"

StdStatisticsSystem::StdStatisticsSystem() {
  reader = new StdStatisticsReader("../score/score_list.bin");
  writer = new StdStatisticsWriter("../score/score_list.bin");
}

StdStatisticsSystem::~StdStatisticsSystem() {
  delete reader;
  delete writer;

  world_system = nullptr;
}

void StdStatisticsSystem::set_location_system(IWorldSystem * input_world_system) {
  world_system = input_world_system;
}

unsigned StdStatisticsSystem::get_records_count() const {
  return reader->get_strings_count();
}

const char* StdStatisticsSystem::get_score_string(unsigned int input_index) const {
  return reader->get_string(input_index);
}

void StdStatisticsSystem::add_score() {
  writer->add_sentient_score(world_system->get_current_map()->get_entities_system()->get_player());
}

void StdStatisticsSystem::free_file() {
  writer->free_file();
}
