//
// Created by pedro on 25/11/17.
//

#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "cliente.h"



//método para iniciar la conección con el servidor
void cliente::init(char* dir[]) {
    direc1.ip = dir[0];
    direc1.ipHA = dir[2];
    direc1.port = atoi(dir[1]);
    direc1.portHA = atoi(dir[3]);

    conectar();
}

bool cliente::conectar() {
    cliente = socket(AF_INET, SOCK_STREAM, 0);
    direccionServidor.sin_family = AF_INET;
    direccionServidor.sin_addr.s_addr = inet_addr(direc1.ip);
    direccionServidor.sin_port = htons(direc1.port);
    for(int i=0;i<2;i++) {
        if (connect(cliente, (sockaddr *) &direccionServidor, sizeof(direccionServidor)) != 0) {
            std::cerr << "No se pudo conectar" << std::endl;
            if(i == 1) {
                std::cout << "Ningún servidor está activo"<<std::endl;
                return false;
            }
            direccionServidor.sin_addr.s_addr = inet_addr(direc1.ipHA);
            direccionServidor.sin_port = htons(direc1.portHA);
        }else{
            char* buffer = new char(100);
            int receivedBytes = recv(cliente, buffer, 100, 0);
            buffer[receivedBytes] = '\0';
            std::cout<<buffer<<std::endl;
            delete(buffer);
            conectado = true;
            return true;
        }
    }
}

void cliente::sendM(char msj[]) {

    if(conectado) {
        try {
            send(cliente, msj, strlen(msj), 0);
        } catch (const std::exception &e) {
            std::cout << "error" << std::endl;
        }

    }

}

void cliente::recibir(char* txt) {
    int receivedBytes = recv(cliente, txt, 100, 0);
    txt[receivedBytes] = '\0';
}