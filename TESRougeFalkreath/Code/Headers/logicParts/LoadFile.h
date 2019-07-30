//
// Created by vydra on 7/28/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_LOADFILE_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_LOADFILE_H_

#include <stdio.h>

class LoadFile {
 private:
  FILE *currentFile_;

 public:
  virtual ~LoadFile() = default;

  bool loadMap(const char *address, int &mapXSize, int &mapYSize, char **map);  // Все переменные кроме
                                                                                               // адреса должны
                                                                                               // изменяться внутри
                                                                                               // функции
  bool loadPlayer() {
    return false;
  }
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_LOADFILE_H_
