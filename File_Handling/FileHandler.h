//
// Created by melany on 27/11/17.
//

#ifndef TEC_MEDIA_FILE_SYSTEM_FILEHANDLER_H
#define TEC_MEDIA_FILE_SYSTEM_FILEHANDLER_H


#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <sys/socket.h>
#include <string>

class FileHandler {
public:
    static std::vector<char> ReadAllBytes(std::string filename);
    void charToBit(std::vector<char> vect, int *ans);

    void createFile(std::vector<char> vect);

    void bitToChar(int *bits, unsigned long sizeBits, char *ans);

    void split(int clients, const int *img, unsigned long totsize, int *parity, int clinum);

    void makeParity(int clients, const int *img, unsigned long totsize, int *parity);

    void useParity(int clients, const int *data, unsigned long totsize, int *result, int clinum);
};


#endif //TEC_MEDIA_FILE_SYSTEM_FILEHANDLER_H
