#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_PLAYMAP_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_PLAYMAP_H_

class playMap {
 private:
  unsigned mapName_;  // Номер карты:
                      // 1 - Фолкрит
                      // 2 - Восточный Лес
                      // 3 - Южные Скальные Сосны

  struct knot {
    char layer0;  // Карта
    char layer1;  // Предмет
    char layer2;  // Непись
    char layer3;  // Игрок
    knot *next1;
    knot *next2;

    knot() {
      layer0 = ' ';
      layer1 = ' ';
      layer2 = ' ';
      layer3 = ' ';
      next1 = nullptr;
      next2 = nullptr;
    }

    ~knot() {
      next1 = nullptr;
      next2 = nullptr;
    }
  };

  typedef knot *pknot;
  unsigned countX_;
  unsigned countY_;
  pknot ph;  // голова
  pknot pb;  // бегунок

  unsigned errorcode;

  bool newKnot1();          // Создаёт в конце линейки первого уровня ещё один узел
  bool newKnot2(unsigned);  // Создаёт в конце линейки второго уроня, заданного положения первого уровня ещё один узел

 public:
  explicit playMap();
  explicit playMap(unsigned, unsigned, unsigned);  // Имя, x,y

  ~playMap();

  bool changeKnot(unsigned, unsigned, char, char, char, char);  // x,y, lay0,lay1,lay2,lay3
  bool pullKnot(unsigned, unsigned, char &, char &, char &, char &);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_PLAYMAP_H_
