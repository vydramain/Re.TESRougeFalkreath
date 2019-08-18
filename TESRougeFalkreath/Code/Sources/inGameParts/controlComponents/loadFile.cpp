#include "inGameParts/controlComponents/loadFile.h"

loadFile::loadFile() {
    currentFile_ = nullptr;
}

loadFile::loadFile(const char *address) {
    currentFile_ = fopen(address, "r");
    if (!currentFile_) {
        fclose(currentFile_);
        currentFile_ = nullptr;
    } else {
        fseek(currentFile_, 0, SEEK_SET);
        if (feof(currentFile_)) {
            fclose(currentFile_);
            currentFile_ = nullptr;
        }
    }
}

loadFile::~loadFile() {
    if (currentFile_) {
        fclose(currentFile_);
    }
    currentFile_ = nullptr;
}

bool loadFile::loadMap(unsigned &mapXSize_, unsigned &mapYSize_, char **&mapChar_) {
    if (mapChar_) {
        for (unsigned i(0); i < mapYSize_; i++) {
            delete mapChar_[i];
        }
        delete mapChar_;
    }
    if (currentFile_) {
        fscanf(currentFile_, "%d", &mapXSize_);
        if (feof(currentFile_)) {
            return 1;
        } else {
            fscanf(currentFile_, "%d", &mapYSize_);
            if (feof(currentFile_)) {
                return 1;
            } else {
                mapChar_ = new char *[mapYSize_];
                for (unsigned i(0); i < mapYSize_; i++) {
                    mapChar_[i] = new char[mapYSize_];
                }
                if (!mapChar_) {
                    for (unsigned i(0); i < mapYSize_; i++) {
                        delete mapChar_[i];
                    }
                    delete mapChar_;
                    return 1;
                } else {
                    for (unsigned i(0); i < mapYSize_; i++) {
                        for (unsigned ii(0); ii < mapXSize_; ii++) {
                            if (feof(currentFile_)) {
                                for (unsigned iii(0); iii < mapYSize_; iii++) {
                                    delete mapChar_[iii];
                                }
                                delete mapChar_;
                                return 1;
                            } else {
                                mapChar_[i][ii] = getc(currentFile_);
                            }
                        }
                    }
                    return 0;
                }
            }
        }
    } else {
        return 1;
    }
}
