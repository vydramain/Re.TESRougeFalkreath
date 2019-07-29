//
// Created by vydra on 7/28/19.
//

#include "logicParts/LoadFile.h"

bool LoadFile::loadMap(const char *address, int &mapXSize, int &mapYSize, char **map) {  // Все переменные
                                                                                         // кроме адреса
                                                                                         // должны
                                                                                         // изменяться
                                                                                         // внутри функции
  currentFile_ = fopen(address, "r");
  if (!currentFile_) {
    fclose(currentFile_);
    return false;
  } else {
    fseek(currentFile_, 0, SEEK_SET);
    if (feof(currentFile_)) {
      fclose(currentFile_);
      return false;
    } else {
      fscanf(currentFile_, "%d", &mapXSize);
      if (feof(currentFile_)) {
        fclose(currentFile_);
        return false;
      } else {
        fscanf(currentFile_, "%d", &mapYSize);
        map = new char *[mapYSize];
        for (int i(0); i < mapYSize; i++) {
          map[i] = new char[mapXSize];
        }
        if (!map) {
          for (int i(0); i < mapYSize; i++) {
            delete map[i];
          }
          delete map;
          fclose(currentFile_);
          return false;
        } else {
          for (int i(0); i < mapYSize; i++) {
            for (int ii(0); ii < mapXSize; ii++) {
              if (feof(currentFile_)) {
                for (int iii(0); iii < mapYSize; iii++) {
                  delete map[iii];
                }
                delete map;
                fclose(currentFile_);
                return false;
              } else {
                map[i][ii] = getc(currentFile_);
              }
            }
          }
          fclose(currentFile_);
          return true;
        }
      }
    }
  }
}
