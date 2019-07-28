//
// Created by vydra on 7/28/19.
//

#ifndef TESROUGEFALKREATH_LOADFILE_H
#define TESROUGEFALKREATH_LOADFILE_H

#include <stdio.h>

class LoadFile {
 private:
    FILE* currentFile_;

   public:
    explicit LoadFile() {}

    bool loadMap(const char* address);

};



#endif //TESROUGEFALKREATH_LOADFILE_H
