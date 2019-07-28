//
// Created by vydra on 7/28/19.
//

#include "logicParts/LoadFile.h"

bool LoadFile::loadMap(const char* address) {
  currentFile_= fopen(address, 'r');
  if(!currentFile_){
    return false;
  } else{
    int mapXSize_, mapYSize_;
    fseek(currentFile_, 0, SEEK_SET);
    if(feof(currentFile_)){
      return false;
    } else{
      fscanf(currentFile_, "%d", mapXSize_);
      if(feof(currentFile_)){
        return false;}
      else{

      fscanf(currentFile_, "%d", mapYSize_);
      char **map;
        map = new char *[mapYSize_];
        for (int i(0); i < mapYSize_; i++) {
          map[i] = new char[mapXSize_];
        }
        if(!map){
          for(int i(0);i<mapYSize_;i++){
            delete map[i];
          } delete map;
          return false;
      } else{

        }
    }
      }
    }
  }
