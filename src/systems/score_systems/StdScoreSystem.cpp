//
// Created by vydra on 8/18/20.
//

#include "systems/score_systems/StdScoreSystem.hpp"

StdScoreSystem::StdScoreSystem() {
  printf("[StdScoreSystem] - open score file\n");
  score_file = fopen("../score/score_list.bin", "a+");
  records_count = 0;
  fseek(score_file, 0, SEEK_SET);
  do {
    int temp = fgetc(score_file);
    if (temp == '\n') {
      records_count++;
    }
  } while (!feof(score_file));
}

StdScoreSystem::~StdScoreSystem() {
  location_system = nullptr;
  if (score_file) {
    fclose(score_file);
    score_file = nullptr;
  }
}

void StdScoreSystem::set_location_system(ILocationSystem* input_location_system) {
  location_system = input_location_system;
}

unsigned StdScoreSystem::get_records_count() const {
  return records_count;
}

const char* StdScoreSystem::get_score_string(unsigned int index) const {
  if (score_file) {
    fseek(score_file, 0, SEEK_SET);
    unsigned counter = 0;
    while (counter != index && !feof(score_file)) {
      int temp = fgetc(score_file);
      if (temp == '\n') {
        counter++;
      }
    }
    if (feof(score_file)) {
      return nullptr;
    }
    int i = 0;
    int character = 0;
    char* returning_string = new char[CHAR_IN_STRING];
    while (character != '\n' && !feof(score_file)) {
      character = fgetc(score_file);
      returning_string[i] = character;
      i++;
    }
    if (i != CHAR_IN_STRING) {
      for (int j = i; j < CHAR_IN_STRING; j++) {
        returning_string[i] = ' ';
      }
    }
    return returning_string;
  }
  return nullptr;
}

void StdScoreSystem::add_score() {
  if (location_system != nullptr) {
    fseek(score_file, 0, SEEK_END);
    fprintf(score_file, "%s", location_system->get_entities()->get_player()->get_fio());
    fprintf(score_file, " - Монет: ");
    char wallet[7];
    snprintf(wallet, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_wallet());
    fprintf(score_file, "%s Шагов: ", wallet);
    char steps[11];
    snprintf(steps, (size_t) "%u", "%u", location_system->get_entities()->get_player()->get_steps_count());
    fprintf(score_file, "%s\n", steps);
  }
}
void StdScoreSystem::free_file() {
  if (score_file) {
    fclose(score_file);
  }
  score_file = fopen("../score/score_list.bin", "w+");
}
