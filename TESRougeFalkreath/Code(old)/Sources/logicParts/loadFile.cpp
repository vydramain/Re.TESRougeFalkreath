//
// Created by vydra on 7/28/19.
//

#include "logicParts/loadFile.h"

bool loadFile::loadMap(const char *address, int &mapXSize_, int &mapYSize_, char **&mapChar_) {
  if (mapChar_) {
    for (int i(0); i < mapYSize_; i++) {
      delete mapChar_[i];
    }
    delete mapChar_;
  }

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
      fscanf(currentFile_, "%d", &mapXSize_);
      if (feof(currentFile_)) {
        fclose(currentFile_);
        return false;
      } else {
        fscanf(currentFile_, "%d", &mapYSize_);
        if (feof(currentFile_)) {
          return false;
        } else {
          mapChar_ = new char *[mapYSize_];
          for (int i(0); i < mapYSize_; i++) {
            mapChar_[i] = new char[mapYSize_];
          }
          if (!mapChar_) {
            for (int i(0); i < mapYSize_; i++) {
              delete mapChar_[i];
            }
            delete mapChar_;
            fclose(currentFile_);
            return false;
          } else {
            for (int i(0); i < mapYSize_; i++) {
              for (int ii(0); ii < mapXSize_; ii++) {
                if (feof(currentFile_)) {
                  for (int iii(0); iii < mapYSize_; iii++) {
                    delete mapChar_[iii];
                  }
                  delete mapChar_;
                  fclose(currentFile_);
                  return false;
                } else {
                  mapChar_[i][ii] = getc(currentFile_);
                 }
              }
            }
            fcloseall();
            // fclose(currentFile_);
            return true;
          }
        }
      }
    }
  }
}
