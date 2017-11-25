//
// Created by luis on 23/11/17.
//https://codereview.stackexchange.com/questions/22901/reading-all-bytes-from-a-file
//


#include "FileHandler.h"


std::vector<char> FileHandler::ReadAllBytes(char const* filename) {
    std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(&result[0], pos);
    ifs.close();

    return result;
}

void FileHandler::charToBit(std::vector<char> vect,int* ans){
    std::vector<char>::const_iterator tconv = vect.begin();
    int i = 0;
    for(;tconv != vect.end(); ++tconv){
        for (int a = 0; a < 8; ++a, i++){
            ans[i] = ((*tconv >> a) & 1);
        }
    }
}

char* FileHandler::bitToChar(int* bits, unsigned long sizeBits){
    char ans[sizeBits/8] = {0};
    int k = 0;
    for(int i = 0;i<sizeBits/8;i++){
        for(int j =7;j != -1;j--){
            ans[i] |= *(bits+k) <<j;
        }
    }
    return ans;
}

void FileHandler::createFile(std::vector<char> vect) {

    std::vector<char> i;
    i.begin() = vect.begin();
    std::ofstream ofs("test.jpeg", std::ofstream::out);
    for (std::vector<char>::const_iterator i = vect.begin(); i != vect.end(); ++i)
        ofs << *i;
    ofs.close();

}