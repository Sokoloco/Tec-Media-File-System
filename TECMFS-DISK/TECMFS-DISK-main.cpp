//
// Created by melany on 27/11/17.
//

#include <iostream>
#include "../Cliente/cliente.cpp"
#include <fstream>

char* dir[] = {"127.0.0.1","8888","127.0.0.1","8881"};




int main() {
    std::cout << "Hello, World!" << std::endl;

    cliente cliente1;
    cliente1.init(dir);
    char msj[] ="DiskNode";
    cliente1.sendM(msj);
    char* txt = new char(1000);
    while (true){
        cliente1.recibir(txt);
        std::cout<<txt;
        std::ofstream fs("../video.txt");
        fs << txt;
        fs.close();

    }

    return 0;
}