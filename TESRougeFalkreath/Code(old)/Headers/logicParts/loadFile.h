//
// Created by vydra on 7/28/19.
//

#ifndef TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_LOADFILE_H_
#define TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_LOADFILE_H_

#include <stdio.h>

class loadFile {
 private:
  FILE *currentFile_;

 public:
  virtual ~loadFile() = default;

  bool loadMap(const char *address, int &mapXSize_, int &mapYSize_, char **&mapChar_);
  bool loadPlayer() {
    return false;
  }
};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_LOGICPARTS_LOADFILE_H_
