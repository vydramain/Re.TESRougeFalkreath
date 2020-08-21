//
// Created by vydra on 8/18/20.
//

#include "systems/score_systems/StdScoreSystem.hpp"

StdScoreSystem::StdScoreSystem() {
  reader = new StdScoreReader("../score/score_list.bin");
  writer = new StdScoreWriter("../score/score_list.bin");
}

StdScoreSystem::~StdScoreSystem() {
  delete reader;
  delete writer;

  location_system = nullptr;
}

void StdScoreSystem::set_location_system(ILocationSystem *input_location_system) {
  location_system = input_location_system;
}

unsigned StdScoreSystem::get_records_count() const {
  return reader->get_strings_count();
}

const char* StdScoreSystem::get_score_string(unsigned int input_index) const {
  return reader->get_string(input_index);
}

void StdScoreSystem::add_score() {
  writer->add_sentient_score(location_system->get_entities()->get_player());
}

void StdScoreSystem::free_file() {
  writer->free_file();
}
