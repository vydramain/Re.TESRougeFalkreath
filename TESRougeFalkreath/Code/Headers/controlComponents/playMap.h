#ifndef TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_PLAYMAP_H_
#define TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_PLAYMAP_H_

class playMap {
 private:
  unsigned mapName_;  // Номер карты:
                      // 1 - Фолкрит
                      // 2 - Восточный Лес
                      // 3 - Южные Скальные Сосны

  struct knot {
    char *layer0;  // Карта
    char *layer1;  // Предмет
    char *layer2;  // Непись
    char *layer3;  // Игрок
    knot *next1;
    knot *next2;

    knot() {
      layer0 = nullptr;  // new char(' ');
      layer1 = nullptr;  // new char(' ');
      layer2 = nullptr;  // new char(' ');
      layer3 = nullptr;  // new char(' ');
      next1 = nullptr;
      next2 = nullptr;
    }

    ~knot() {
      delete layer0;
      delete layer1;
      delete layer2;
      delete layer3;
    }

    void rewriteKnot(char lay0, char lay1, char lay2, char lay3) {
      delete layer0;
      delete layer1;
      delete layer2;
      delete layer3;

      layer0 = new char(lay0);
      layer1 = new char(lay1);
      layer2 = new char(lay2);
      layer3 = new char(lay3);
    }
    void rewriteKnot0(char lay) {
      delete layer0;

      layer0 = new char(lay);
    }
    void rewriteKnot1(char lay) {
      delete layer1;

      layer1 = new char(lay);
    }
    void rewriteKnot2(char lay) {
      delete layer2;

      layer2 = new char(lay);
    }
    void rewriteKnot3(char lay) {
      delete layer3;

      layer3 = new char(lay);
    }

    char viewKnot0() {
      return *layer0;
    }
    char viewKnot1() {
      return *layer1;
    }
    char viewKnot2() {
      return *layer2;
    }
    char viewKnot3() {
      return  *layer3;
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
  bool changeKnot0(unsigned, unsigned, char);
  bool changeKnot1(unsigned, unsigned, char);
  bool changeKnot2(unsigned, unsigned, char);
  bool changeKnot3(unsigned, unsigned, char);

  bool pullKnot(unsigned, unsigned, char &, char &, char &, char &);
  bool pullKnot0(unsigned, unsigned, char &);
  bool pullKnot1(unsigned, unsigned, char &);
  bool pullKnot2(unsigned, unsigned, char &);
  bool pullKnot3(unsigned, unsigned, char &);

  void setName(unsigned Name);
  unsigned viewName();
  unsigned viewSizeX();
  unsigned viewSizeY();
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_CONTROLCOMPONENTS_PLAYMAP_H_
