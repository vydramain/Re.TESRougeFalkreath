#include "inGameParts/logicComponents/player.h"

player::player() {
  areaPlaceX_ = 0;
  areaPlaceY_ = 0;

  for (unsigned i(0); i < NAMESPACE; i++) {
    name_[i] = ' ';
  }

  HP_ = 0;
  AP_ = 0;
  MP_ = 0;
}

player::player(char* NAME, unsigned X, unsigned Y, unsigned RACE) {
  areaPlaceX_ = X;
  areaPlaceY_ = Y;

  for (unsigned i(0); i < NAMESPACE; i++) {
    name_[i] = NAME[i];
  }

  status_ = 1;
}

player::~player() {}

bool player::changeName(char* NAME) {
  for (unsigned i(0); i < NAMESPACE; i++) {
    name_[i] = NAME[i];
  }
  return 0;
}

bool player::changeLocation(unsigned X, unsigned Y) {
  areaPlaceX_ = X;
  areaPlaceY_ = Y;
  return 0;
}

bool player::changeStatus(unsigned STATUS) {
  status_ = STATUS;
  return 0;
}

bool player::changeCourse(unsigned CURSE) {
  course_ = CURSE;
  return 0;
}

bool player::changeNationality(unsigned N) {
  switch (N) {
    case 1: {  // Норд
      nationality_ = 1;
      HP_ = 120;
      AP_ = 90;
      MP_ = 90;
      return 0;
    }
    case 2: {  // Бретонец
      nationality_ = 2;
      HP_ = 80;
      AP_ = 110;
      MP_ = 110;
      return 0;
    }
    case 3: {  // Редгард
      nationality_ = 3;
      HP_ = 100;
      AP_ = 120;
      MP_ = 80;
      return 0;
    }
    case 4: {  // Имперец
      nationality_ = 4;
      HP_ = 100;
      AP_ = 100;
      MP_ = 100;
      return 0;
    }
    case 5: {  // Высокий Эльф
      nationality_ = 5;
      HP_ = 80;
      AP_ = 80;
      MP_ = 140;
      return 0;
    }
    case 6: {  // Тёмный Эльф
      nationality_ = 6;
      HP_ = 90;
      AP_ = 90;
      MP_ = 120;
      return 0;
    }
    case 7: {  // Лесной Эльф
      nationality_ = 7;
      HP_ = 80;
      AP_ = 140;
      MP_ = 80;
      return 0;
    }
    case 8: {  // Орк
      nationality_ = 8;
      HP_ = 130;
      AP_ = 90;
      MP_ = 80;
      return 0;
    }
    case 9: {  // Аргонианин
      nationality_ = 9;
      HP_ = 140;
      AP_ = 80;
      MP_ = 80;
      return 0;
    }
    case 10: {  // Каджит
      nationality_ = 10;
      HP_ = 70;
      AP_ = 120;
      MP_ = 110;
      return 0;
    }
    default: {
      nationality_ = 0;
      HP_ = 0;
      AP_ = 0;
      MP_ = 0;
      return 1;
    }
  }
}

bool player::changePoints(unsigned H, unsigned A, unsigned M) {
  HP_ += H;
  AP_ += A;
  MP_ += M;
  return 0;
}

void player::viewName(char* NAME) {
  for (unsigned i(0); i < NAMESPACE; i++) {
    NAME[i] = name_[i];
  }
}

void player::viewLocation(unsigned& X, unsigned& Y) {
  X = areaPlaceX_;
  Y = areaPlaceY_;
}

void player::viewStatus(unsigned& STATUS) {
  STATUS = status_;
}

void player::viewCourse(unsigned& CURSE) {
  CURSE = course_;
}

void player::viewNationality(unsigned& N) {
  N = nationality_;
}

void player::viewPoints(unsigned& H, unsigned& A, unsigned& M) {
  H = HP_;
  A = AP_;
  M = MP_;
}