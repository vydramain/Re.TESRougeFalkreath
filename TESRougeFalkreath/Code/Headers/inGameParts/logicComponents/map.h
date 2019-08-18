#ifndef TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_MAP_H_
#define TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_MAP_H_

class map {
 private:
  bool errsMap_;
  unsigned mapName_;  // Номер карты:
                      // 1 - Фолкрит
                      // 2 - Восточный Лес
                      // 3 - Южные Скальные Сосны
  char** mapChar_;
  unsigned mapXSize_, mapYSize_;

 public:
  explicit map();
  explicit map(const unsigned&, const unsigned&, const unsigned&, char**);  // номер соответствующей локации
  ~map();

  char viewMapChar(const unsigned&, const unsigned&);
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_LOGICCOMPONENTS_MAP_H_
