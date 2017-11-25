//
// Created by luis on 23/11/17.
//

#ifndef TEC_MEDIA_FILE_SYSTEM_FILEHANDLER_H
#define TEC_MEDIA_FILE_SYSTEM_FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <sys/socket.h>

class FileHandler {
public:
    static std::vector<char> ReadAllBytes(char const* filename);
    void charToBit(std::vector<char> vect, int *ans);

    void createFile(std::vector<char> vect);

    char *bitToChar(int *bits, unsigned long sizeBits);
};

#endif //TEC_MEDIA_FILE_SYSTEM_FILEHANDLER_H
