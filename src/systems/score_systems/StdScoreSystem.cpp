//
// Created by vydra on 8/18/20.
//

#include "systems/score_systems/StdScoreSystem.hpp"

StdScoreSystem::StdScoreSystem() {
  printf("[StdScoreSystem] - open score file\n");
  score_file = fopen("../score/score_list.bin", "a+");
}

StdScoreSystem::~StdScoreSystem() {
  location_system = nullptr;
  if (score_file) {
    fclose(score_file);
    score_file = nullptr;
  }
  if (score_file) {
    score_file = nullptr;
    score_count = 0;
    printf("[StdScoreSystem] - error opening score file\n");
    return;
  }
  fseek(score_file, 0, SEEK_SET);
  char temp[CHAR_IN_STRING];
  for (score_count = 0; fgets(temp, CHAR_IN_STRING, score_file); score_count++) {
  }
}

void StdScoreSystem::set_location_system(ILocationSystem* input_location_system) {
  location_system = input_location_system;
}

unsigned StdScoreSystem::get_score_count() const {
  return score_count;
}

const char* StdScoreSystem::get_score_string(unsigned int index) const {
  if (score_file) {
    fseek(score_file, CHAR_IN_STRING * index, SEEK_SET);
    char* returning_string = new char[CHAR_IN_STRING];
    fgets(returning_string, CHAR_IN_STRING, score_file);
    return returning_string;
  }
  return nullptr;
}

void StdScoreSystem::add_score() {
  // имяимяимяимяимяимяимяимя - Монет: 1234566 Шагов: 12345667890
  if (location_system != nullptr) {
    fseek(score_file, 0, SEEK_END);
    fprintf(score_file, "%s", location_system->get_entities()->get_player()->get_fio());
    for (unsigned i = 0; i < location_system->get_entities()->get_player()->get_chars_counts() -
                                 strlen(location_system->get_entities()->get_player()->get_fio());
         i++) {
      fprintf(score_file, " ");
    }
    fprintf(score_file, " - Монет: ");
    char wallet[7];
    snprintf(wallet, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_wallet());
    fprintf(score_file, "%s Шагов: ", wallet);
    char steps[11];
    snprintf(steps, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_steps_count());
    fprintf(score_file, "%s\n", steps);
  }
}
