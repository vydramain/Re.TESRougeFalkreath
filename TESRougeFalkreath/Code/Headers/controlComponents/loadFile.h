//
// Created by vydra on 7/28/19.
//

#ifndef  TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_LOADFILE_H_
#define  TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_LOADFILE_H_

#include <stdio.h>

class loadFile{
private:
    FILE *currentFile_;

public:
    explicit loadFile();
    explicit loadFile(const char*);
    ~loadFile();

    bool loadMap(unsigned &,unsigned &, char **&);


};

#endif  // TESROUGEFALKREATH_CODE_HEADERS_INGAMEPARTS_CONTROLCOMPONENTS_LOADFILE_H_
