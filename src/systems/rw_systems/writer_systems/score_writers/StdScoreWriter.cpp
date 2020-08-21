//
// Created by vydra on 8/21/20.
//

#include <systems/rw_systems/writer_systems/score_writers/StdScoreWriter.hpp>

StdScoreWriter::StdScoreWriter(const char *input_file_name) {
  PseudoLogSystem::log("StdScoreWriter", "Try to open", input_file_name);
  file_name = input_file_name;
  current_file = fopen(input_file_name, "a+");
  if (current_file == nullptr) {
    PseudoLogSystem::log("StdScoreWriter", "Can not open", input_file_name);
  }
}

StdScoreWriter::~StdScoreWriter() {
  if (current_file != nullptr) {
    fclose(current_file);
  }
}

void StdScoreWriter::free_file() {
  if (current_file != nullptr) {
    fclose(current_file);
  }
  current_file = fopen(file_name, "w+");
}

void StdScoreWriter::add_sentient_score(Sentient *input_sentient) {
  if (input_sentient != nullptr && current_file != nullptr) {
    fseek(current_file, 0, SEEK_END);
    fprintf(current_file, "%s", input_sentient->get_fio());
    fprintf(current_file, " - Монет: ");
    char wallet[7];
    snprintf(wallet, (size_t) "%u", "%u", input_sentient->get_wallet());
    fprintf(current_file, "%s Шагов: ", wallet);
    char steps[11];
    snprintf(steps, (size_t) "%u", "%u", input_sentient->get_steps_count());
    fprintf(current_file, "%s\n", steps);
  }
}
