//
// Created by vydra on 8/6/19.
//

#include "logicParts/npcs.h"

npcs::npcs() {
  for (unsigned i(0); i < 24; i++) {
    npcName_[i] = 0;
  }
}

npcs::npcs(char *Name, unsigned Nation) {
  unsigned range = sizeof(Name) / sizeof(char);
  for (unsigned i(0); i < range; i++) {
    npcName_[i] = Name[i];
  }
  npcNation_ = Nation;
}

void npcs::pullTerrain(unsigned xm, unsigned ym) {
  mapY_ = ym;
  mapX_ = xm;
}

void npcs::makeDiaog(unsigned count) {
  npcPhrases_ = new char **[count];
  for (unsigned i(0); i < count; i++) {
    npcPhrases_[i] = new char *[2];
  }
  countPhrases_ = count;
}

void npcs::addDialog(const char *phraseUp, const char *phraseDown, unsigned countLettersUp, unsigned countLettersDown, unsigned number) {
  npcPhrases_[number][0] = new char[countLettersUp];
  npcPhrases_[number][1] = new char[countLettersDown];
  strcpy(npcPhrases_[number][0], phraseUp);
  strcpy(npcPhrases_[number][1], phraseDown);
}

void npcs::elimDialog() {
  for (unsigned i(0); i < countPhrases_; i++) {
    for (unsigned ii(0); ii < 2; ii++) {
      delete[] npcPhrases_[i][ii];
    }
    delete[] npcPhrases_[i];
  }
  delete[] npcPhrases_;
}

void npcs::makeAnswer(unsigned countAnswers, unsigned countVariables) {
  npcAnswers_ = new char **[countAnswers];
  for (unsigned i(0); i < countAnswers; i++) {
    npcAnswers_[i] = new char *[countVariables];
  }
  countAnswers_ = countAnswers;
}

void npcs::addAnswer(const char *phrase, unsigned countLetters, unsigned numberAnswer, unsigned numberVariable) {
  npcAnswers_[numberAnswer][numberVariable] = new char[countLetters];
  strcpy(npcAnswers_[numberAnswer][numberVariable], phrase);
}

void npcs::elimAnswer() {
  for (unsigned i(0); i < countAnswers_; i++) {
    for (unsigned ii(0); ii < countVariables_; ii++) {
      delete[] npcAnswers_[i][ii];
    }
    delete[] npcAnswers_[i];
  }
  delete[] npcAnswers_;
}
