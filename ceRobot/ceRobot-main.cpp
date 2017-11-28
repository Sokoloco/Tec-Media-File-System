//
// Created by melany on 27/11/17.
//

//Ejecutar así
/**
g++ -I/usr/local/include/opencv -I/usr/local/include/opencv2 -L/usr/local/lib/ -g -o CR  ceRobot/ceRobot-main.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching -std=c++11

**/
/*
#include <iostream>
//#include "FileHandler.h"
#include "../ImageProcessing/Processing.cpp"
#include "../Cliente/cliente.cpp"

Processing processing1;
//FileHandler file;
cliente cliente1;
char* ip[] = {"127.0.0.1","8888","127.0.0.1","8881"};


int main() {
    cliente1.init(ip);
    std::cout << "Hello, World!" << std::endl;
    std::string dir;
    std::cout<<"Ingrese la dirección del video que desee guardar:";
    std::cin>>dir;
    processing1.ShowVideo(dir);
    std::vector<char> x;


    return 0;
}*/

//
// Created by pedro on 27/11/17.
//

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <vector>
#include <sys/socket.h>
#include "../File_Handling/FileHandler.cpp"
#include "../ImageProcessing/Processing.cpp"
#include "../Cliente/cliente.h"
#include <ostream>
#include <string>

Processing processing1;
FileHandler fileHandler;
cliente cliente1;

int FrameDir(std::string Carpeta);

char* ip[] = {"127.0.0.1","8888","127.0.0.1","8881"};

void explorer(const char* directory){
    DIR* dir;
    struct dirent* entry;
    struct stat info;

    //open
    dir = opendir(directory);
    if (!dir){
        std::cout << "Directory was not found" << std::endl;
    }
    //read
    while ((entry = readdir(dir)) != NULL){
        if(entry->d_name[0] != '.'){
            std::string path = std::string(directory) + "/" + std::string(entry->d_name);
            //Aca es donde debe estar la linea de enviar al server
            processing1.ShowVideo(path,entry->d_name);

            stat(path.c_str(),&info);
            if(S_ISDIR(info.st_mode)){
                explorer(path.c_str());
            }
        }
    }
    //close
    closedir(dir);

}

void explorer2(const char* directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    //open
    dir = opendir(directory);
    if (!dir) {
        std::cout << "Directory was not found" << std::endl;
    }
    //read
    cliente1.conectar();
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            std::string path = std::string(directory) + "/" + std::string(entry->d_name);
            //Aca es donde debe estar la linea de enviar al server
            //processing1.ShowVideo(path, entry->d_name);
            bool stop=true;
            for (int i=0; stop ;i++) {
                std::string num = std::to_string(i);
                std::string dir = path + "/" + std::string(entry->d_name) + num + ".jpg";
                stop = std::ifstream (dir).good;
                std::vector<char> vect = fileHandler.ReadAllBytes(dir);
                std::ostringstream ostringstream;
                for (int a=0;a<vect.size();a++){
                    ostringstream << vect.at(a);
                }
                cliente1.sendM((char*)(ostringstream.str().c_str()));
            }


            stat(path.c_str(), &info);
            if (S_ISDIR(info.st_mode)) {
                explorer(path.c_str());
            }
        }
    }
    //close
    closedir(dir);
}

int main() {
    /*
     * g++ -I/usr/local/include/opencv -I/usr/local/include/opencv2 -L/usr/local/lib/ -g -o CR  ceRobot/ceRobot-main.cpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching -std=c++11
     */
    cliente1.init(ip);
    cliente1.conectar();
    std::cout << "Hello, World!" << std::endl;
    std::string rec;
    const char* dir;
    //std::cout<<"Ingrese la dirección del video que desee guardar:";
    std::cout<<"Ingrese la dirección de la carpeta que desee guardar:";
    std::cin>>rec;
    //dir = (char*)("/home/melany/CLionProjects/Videos");
    dir = rec.c_str();
    std::cout << dir << std::endl;
    explorer(dir);


    return 0;
}