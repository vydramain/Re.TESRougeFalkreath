#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_PLAYER_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_PLAYER_H_

#ifndef NAMESPACE_U
#define NAMESPACE 24

#endif  // NAMECPACE_U

class player {
 private:
  unsigned areaPlaceX_, areaPlaceY_;

  unsigned course_ = 2;  // Направление в котором последний раз двигался персонаж:
                         // 0 -вврех,
                         // 1 -вниз,
                         // 2 -влево,
                         // 3 -вправо.

  char name_[NAMESPACE];

  unsigned status_ = 0;  // Состояние игрока:
                         // 0 - Мёртв
                         // 1 - Обычное состояние
                         // 2 - Спрятался
                         // 3 - Диалог

  unsigned HP_;  // Очки Здоровья
  unsigned AP_;  // Очки Действий
  unsigned MP_;  // Очки Магии

  unsigned nationality_;  // Расы:
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
  unsigned wallet_;

  unsigned oldAct;
  bool changeArea;
  bool endGame;

 public:
  explicit player();
  explicit player(char *, unsigned, unsigned);  // создаём рабочего персонажа
  ~player();

  bool changeName(char *Name);
  bool changeLocation(unsigned X, unsigned Y);
  bool changeCourse(unsigned Course);
  bool changeStatus(unsigned Status);
  bool changeNationality(unsigned Nationality);
  bool changePoints(unsigned HP, unsigned AP, unsigned MP);
  bool changeCoinsCount(unsigned Count);

  char* viewName();
  unsigned viewLocationX();
  unsigned viewLocationY();
  unsigned viewCourse();
  unsigned viewStatus();
  unsigned viewNationality();
  unsigned viewPointsHP();
  unsigned viewPointsAP();
  unsigned viewPointsMP();
  unsigned viewCoinsCount();

  void changeOldAct(unsigned OldAct);
  unsigned conditionOldAct();

  void changeChangeArea(bool ChangeArea);
  bool conditionChangeArea();

  void changeEndGame(bool EndGame);
  bool conditionEndGame();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_PLAYER_H_
