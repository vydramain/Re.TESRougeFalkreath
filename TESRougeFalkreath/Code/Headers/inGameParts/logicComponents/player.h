#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_PLAYER_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_PLAYER_H_

#ifndef NAMESPACE_U
#define NAMESPACE 24

#endif  // NAMECPACE_U

class player {
 private:
  unsigned areaPlaceX_, areaPlaceY_;

  unsigned course_ = 1;  // Направление в котором последний раз двигался персонаж:
                         // 0 -вврех,
                         // 1 -влево,
                         // 2 -вправо,
                         // 3 -вниз.

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
 public:
  explicit player();
  explicit player(char*, unsigned, unsigned, unsigned);
  ~player();

  bool changeName(char*);
  bool changeLocation(unsigned, unsigned);
  bool changeCourse(unsigned);
  bool changeStatus(unsigned);
  bool changeNationality(unsigned);
  bool changePoints(unsigned, unsigned, unsigned);

  void viewName(char*);
  void viewLocation(unsigned&, unsigned&);
  void viewCourse(unsigned&);
  void viewStatus(unsigned&);
  void viewNationality(unsigned&);
  void viewPoints(unsigned&, unsigned&, unsigned&);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_PLAYER_H_
