//
// Created by pedro on 27/11/17.
//

#include <iostream>
//#include "FileHandler.h"
#include "../ImageProcessing/Processing.h"
#include "../Cliente/cliente.h"

Processing processing1;
//FileHandler file;
cliente cliente1;
char* ip[] = {"127.0.0.1","8080","127.0.0.1","8081"};


int main() {
    cliente1.init(ip);
    std::cout << "Hello, World!" << std::endl;
    std::string dir;
    std::cout<<"Ingrese la dirección del video que desee guardar:";
    std::cin>>dir;
    processing1.ShowVideo(dir);
    std::vector<char> x;


    return 0;
}