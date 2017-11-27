#include <iostream>
#include "../Cliente/cliente.h"
#include <fstream>

char* dir[] = {"127.0.0.1","8080","127.0.0.1","8081"};




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