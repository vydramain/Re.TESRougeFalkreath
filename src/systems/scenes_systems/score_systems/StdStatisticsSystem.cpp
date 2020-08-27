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

  location_system = nullptr;
}

void StdStatisticsSystem::set_location_system(ILocationSystem *input_location_system) {
  location_system = input_location_system;
}

unsigned StdStatisticsSystem::get_records_count() const {
  return reader->get_strings_count();
}

const char* StdStatisticsSystem::get_score_string(unsigned int input_index) const {
  return reader->get_string(input_index);
}

void StdStatisticsSystem::add_score() {
  writer->add_sentient_score(location_system->get_entities()->get_player());
}

void StdStatisticsSystem::free_file() {
  writer->free_file();
}
