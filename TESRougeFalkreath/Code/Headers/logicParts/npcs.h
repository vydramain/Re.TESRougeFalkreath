//
// Created by vydra on 8/6/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_NPCS_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_NPCS_H_

#include <cstring>

class npcs {
 public:
  char naked = 'i';  // игрок без брони

  int mapX_ = 0, mapY_ = 0;  // для размещения на карте
  unsigned course = 1;            //  направление в котором последний раз двигался персонаж
                                  // 0 -вврех,
                                  // 1 -влево,
                                  // 2 -вправо,
                                  // 3 -вниз.

  char npcName_[24];
  char ***npcPhrases_;
  char ***npcAnswers_;
  unsigned countPhrases_;
  unsigned countAnswers_;
  unsigned countVariables_;
  unsigned HP_;
  unsigned MP_;
  unsigned AP_;
  unsigned SP_;
  unsigned status_ = 0;  // Cостояние npcs:
                         // 0. Мёртв
                         // 1. Обычное состояние
                         // 2. Агрессивен
                         // 3. Обижен
                         // 4. Напуган

  unsigned npcNation_;  // Расы:
                        // 1. Норд
                        // 2. Бретон
                        // 3. Редгард
                        // 4. Имперец
                        // 5. Высокий эльф
                        // 6. Тёмный эльф
                        // 7. Лесной эльф
                        // 8. Орк
                        // 9. Аргонианин
                        // 10. Каджит
  int attack_;
  float block_;
  unsigned armorSlot_;
  unsigned weaponSlot_;
  //  items inventory[6];

  explicit npcs();
  explicit npcs(char *Name, unsigned Nation);
  ~npcs() {}


  void pullTerrain(unsigned xm, unsigned ym);

  void makeDiaog(unsigned count);
  void addDialog(const char *phraseUp, const char *phraseDown, unsigned countLettersUp, unsigned countLettersDown, unsigned number);
  void elimDialog();

  void makeAnswer(unsigned countAnswers, unsigned countVariables);
  void addAnswer(const char *phrase, unsigned countLetters, unsigned numberAnswer, unsigned numberVariable);
  void elimAnswer();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_NPCS_H_
